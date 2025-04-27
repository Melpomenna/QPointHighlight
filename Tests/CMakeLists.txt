set(target Tests)

add_executable(${target} 
     main.tests.cpp   
)

target_include_directories(${target} PRIVATE ${CMAKE_SOURCE_DIR}/Include)

target_link_libraries(${target} PRIVATE GTest::gtest_main ArchitectureCore Async)

include(CompilerOptions)
SetCompilerOptions(${target})
include(ClangTidyOptions)
UseClangTidy(${target})

include(GoogleTest)
gtest_discover_tests(${target})