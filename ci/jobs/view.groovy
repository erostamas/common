sectionedView("common_${BRANCH_NAME}") {
    filterExecutors()
    sections {
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
