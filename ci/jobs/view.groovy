sectionedView("common_${BRANCH_NAME}") {
    filterExecutors()
    sections {
        listView {
            name('HEAD')
            alignment('LEFT')
            width('HALF')
            jobs {
                name("common_library_build_${BRANCH_NAME}")
                name("common_build_image_build_${BRANCH_NAME}")
            }
            columns {
                status()
                weather()
                name()
                lastBuildNode()
                lastBuildConsole()
            }
        }
        listView {
            name('Gerrit - Review')
            alignment('LEFT')
            width('HALF')
            jobs {
                name("gerrit_common_library_build_${BRANCH_NAME}")
            }
            columns {
                status()
                weather()
                name()
                lastBuildNode()
                lastBuildConsole()
            }
        }
    }
}
