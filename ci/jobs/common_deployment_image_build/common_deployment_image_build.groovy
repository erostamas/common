import groovy.json.*

def jobname = "common_deployment_image_build_${BRANCH_NAME}"

freeStyleJob(jobname) {
    description("""
        <b>Generated Job</b>
        <p>Common library deployment image build
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
                credentials('c9236555-4efa-4139-af71-3c87df24743e')
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
            ${WORKSPACE}/common/ci/jobs/common_deployment_image_build/build.sh
        '''.stripIndent().trim())
    }
}
