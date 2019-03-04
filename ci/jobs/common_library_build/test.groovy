import groovy.json.*

def jobname = "test_${BRANCH_NAME}"

node('master') {
    stage('DSL') {
        sh 'env'
        jobDsl scriptText:'System.getenv().collect{println it.key println it.value}'
    }
}
freeStyleJob(jobname) {
    description("""
        <b>Generated Job</b>
        <p>Common library build
    """.stripIndent().trim())
    logRotator{
        numToKeep(10)
        artifactNumToKeep(10)
    }
    parameters {
        stringParam('GERRIT_REFSPEC', "refs/heads/${BRANCH_NAME}", '"Build Now" workaround')
    }
    concurrentBuild()
    scm {
        git {
            remote{
                url("ssh://erostamas@review.gerrithub.io:29418/erostamas/common")
                refspec('$GERRIT_REFSPEC')
            }
            branch("${BRANCH_NAME}")
            extensions{
                choosingStrategy {
                    gerritTrigger()
                }
                cleanBeforeCheckout()
                relativeTargetDirectory('common')
            }
        }
    }
    triggers {
        gerrit {
            project('erostamas/common', "${BRANCH_NAME}")
			events {
                changeMerged()
            }
            configure { gerrit ->
                gerrit / serverName('Gerrithub')
                gerrit / silentStartMode(true)
                gerrit / 'gerritProjects' /
                    'com.sonyericsson.hudson.plugins.gerrit.trigger.hudsontrigger.data.GerritProject' << {
                        'forbiddenFilePaths' {
                            'com.sonyericsson.hudson.plugins.gerrit.trigger.hudsontrigger.data.FilePath' {
                                'pattern'('README.md')
                                'compareType'('ANT')
                            }
                        }
                    }
            }
        }
    }
    wrappers {
        timeout {
            absolute(60)
        }
        timestamps()
        colorizeOutput('xterm')
    }
    steps{
        shell('''
            ${WORKSPACE}/common/ci/jobs/common_library_build/main.sh --cached
        '''.stripIndent().trim())
    }
    publishers {
        archiveArtifacts {
            pattern('common/build/logging/libet_logging.so, ' +
                    'common/logging/Logging.h, ' +
					'common/build/config/libet_config.so, ' +
                    'common/config/Config.h' )
        }
    }
}
