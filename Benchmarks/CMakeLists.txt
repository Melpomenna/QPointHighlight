set(target Benchmarks)

add_executable(${target} 
    main.becnhmarks.cpp   
)

target_include_directories(${target} PRIVATE ${CMAKE_SOURCE_DIR}/Include)

target_link_libraries(${target} benchmark::benchmark Async ArchitectureCore Qt6::Core)

include(CompilerOptions)
SetCompilerOptions(${target})
include(ClangTidyOptions)
UseClangTidy(${target})
