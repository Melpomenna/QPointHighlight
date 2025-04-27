cmake_minimum_required(VERSION 3.19)

project(PointHighlight VERSION 1.0.0 LANGUAGES CXX)

enable_testing(TRUE)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Gui)
find_package(CUDA)

qt_standard_project_setup()

set(SourceDir ${CMAKE_CURRENT_SOURCE_DIR}/Source)
set(IncludeDir ${CMAKE_CURRENT_SOURCE_DIR}/Include)
set(UIDir ${CMAKE_CURRENT_SOURCE_DIR}/UI)

set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}:${CMAKE_MODULE_PATH}:${IncludeDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_AUTOUIC_SEARCH_PATHS};${UIDir}")

set(BENCHMARK_ENABLE_GTEST_TESTS  OFF CACHE BOOL "Whether to install benchmark")
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Disable tests")
set(BENCHMARK_INSTALL_DOCS OFF CACHE BOOL "Disable docs")

add_definitions(-DDEFAULT_POINTS_RADIUS=16)
add_definitions(-DDEFAULT_POINTS_COUNT=50)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/CMake)


qt_add_executable(${PROJECT_NAME}
    WIN32 MACOSX_BUNDLE
    ${SourceDir}/main.cpp
    ${UIDir}/MainWindow.ui
    ${SourceDir}/MainWindow.cpp
    ${SourceDir}/RenderWidget.cpp
    ${IncludeDir}/MainWindow.h
    ${IncludeDir}/RenderWidget.h
    Resources/resource.qrc
)

include_directories(${IncludeDir} ${UIDir})

if (CUDA_FOUND)
    include_directories(${CUDA_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${CUDA_LIBRARIES})
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        ArchitectureCore
        Async
        RenderHelpers
)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

include(CompilerOptions)
SetCompilerOptions(${PROJECT_NAME})
include(ClangTidyOptions)
UseClangTidy(${PROJECT_NAME})

qt_generate_deploy_app_script(
    TARGET ${PROJECT_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

add_subdirectory(ThirdParty)
add_subdirectory(Tests)
add_subdirectory(Benchmarks)
add_subdirectory(${SourceDir}/ArchitectureCore)
add_subdirectory(${SourceDir}/Async)
add_subdirectory(${SourceDir}/Render)