set(target Tests)

add_executable(${target} 
     main.tests.cpp   
)

target_link_libraries(${target} PRIVATE Qt6::Core Qt6::Gui GTest::gtest_main GTest::gmock ArchitectureCore Async)

include(CompilerOptions)
SetCompilerOptions(${target})
include(ClangTidyOptions)
UseClangTidy(${target})

include(GoogleTest)
gtest_discover_tests(${target})