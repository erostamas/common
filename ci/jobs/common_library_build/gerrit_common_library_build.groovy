import groovy.json.*

def jobname = "gerrit_common_library_build_${BRANCH_NAME}"

freeStyleJob(jobname) {
    description("""
        <b>Generated Job</b>
        <p>Common library build - Gerrit
    """.stripIndent().trim())
    logRotator{
        numToKeep(10)
        artifactNumToKeep(10)
    }
    parameters {
        stringParam('GERRIT_REFSPEC', "refs/heads/${BRANCH_NAME}", '"Build Now" workaround')
        stringParam('BRANCH_NAME', "${BRANCH_NAME}", 'Make BRANCH_NAME available in the job scripts')
    }
    concurrentBuild()
    scm {
        git {
            remote{
                url("ssh://erostamas@review.gerrithub.io:29418/erostamas/common")
                refspec('$GERRIT_REFSPEC')
                credentials('33782a32-8ca5-49a6-9808-3f634b6f4972')
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
                patchsetCreated()
            }
            configure { gerrit ->
                gerrit / serverName('Gerrithub')
                gerrit / 'triggerOnEvents' /
                    'com.sonyericsson.hudson.plugins.gerrit.trigger.hudsontrigger.events.PluginCommentAddedContainsEvent' /
                        'commentAddedCommentContains'('.*rebuild.*')
                gerrit / 'triggerOnEvents' /
                    'com.sonyericsson.hudson.plugins.gerrit.trigger.hudsontrigger.events.PluginPatchsetCreatedEvent' /
                        'excludeDrafts'(true)
                gerrit / 'gerritProjects' /
                    'com.sonyericsson.hudson.plugins.gerrit.trigger.hudsontrigger.data.GerritProject' << {
                        'filePaths' {
                            'com.sonyericsson.hudson.plugins.gerrit.trigger.hudsontrigger.data.FilePath' {
                                'pattern'('*/**')
                                'compareType'('ANT')
                            }
                        }
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
