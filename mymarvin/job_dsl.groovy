// freeStyleJob('${DISPLAY_NAME}') {
//     scm {
//         git {
//             remote {
//                 url('https://github.com/${GITHUB_NAME}.git')
//             }
//             branch('*/main')
//         }
//     }
//     triggers {
//         scm('* * * * *')
//     }
//     wrappers {
//         preBuildCleanup()
//     }
//     steps {
//         shell('make fclean')
//         shell('make')
//         shell('make tests_run')
//         shell('make clean')
//     }
// }



// ---------------------------------------- //
folder('/Tools') {
    displayName('Tools')
    description('Folder for miscellaneous tools.')
}

freeStyleJob('/Tools/clone-repository') {
    wrappers {
        preBuildCleanup()
    }
    parameters {
        stringParam("GIT_REPOSITORY_URL", "", "Git URL of the repository to clone")
    }
    steps {
        shell('git clone ${GIT_REPOSITORY_URL}')
    }
}

freeStyleJob('/Tools/SEED') {
    // wrappers {
    //     preBuildCleanup()
    // }
    parameters {
        stringParam("GITHUB_NAME", "", 'GitHub repository owner/repo_name (e.g.: "EpitechIT31000/chocolatine")')
        stringParam("DISPLAY_NAME", "", "Display name for the job")
    }
    steps {
        dsl {
            text('''freeStyleJob("${DISPLAY_NAME}") {
                wrappers {
                    preBuildCleanup()
                }
                scm {
                    github("${GITHUB_NAME}")
                }
                triggers {
                    scm('* * * * *')
                }
                steps {
                    shell("make fclean")
                    shell("make")
                    shell("make tests_run")
                    shell("make clean")
                }
            }''')
        }
    }
}
