function(SetCompilerOptions target)
    message(STATUS "Use compiler options")

    if (UNIX)
        if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
            message(STATUS "Use compile arguments for module name: ${target}, preset:Debug")
            target_compile_options(${target} PRIVATE -Wall -Werror -Wextra -g -O0 -fsanitazer=address -std=c++${CMAKE_CXX_STANDARD})
        elseif (${CMAKE_BUILD_TYPE} MATCHES "Release")
            message(STATUS "Use compile arguments for module name: ${target}, preset:Release")
            target_compile_options(${target} PRIVATE -Wall -Werror -Wextra -O3 -std=c++{CMAKE_CXX_STANDARD})
        else ()
            message(FATAL_ERROR "Unknown build type: module name: ${target}")
        endif ()
    elseif(MSVC)
        if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
            message(STATUS "Use compile arguments for module name: ${target}, preset:Debug")
            target_compile_options(${target} PRIVATE /W4 /WX /Zi /fsanitize=address /Od /MDd /std:c++${CMAKE_CXX_STANDARD} )
            add_link_options(/INCREMENTAL:NO)
            add_compile_options(-fsanitize=address)
        elseif (${CMAKE_BUILD_TYPE} MATCHES "Release")
            message(STATUS "Use compile arguments for module name: ${target}, preset:Release")
            target_compile_options(${target} PRIVATE /W4 /WX /O2 /MD /std:c++${CMAKE_CXX_STANDARD} )
        else ()
            message(FATAL_ERROR "Unknown build type: module name: ${target}")
        endif ()
    else()
        message(FATAL_ERROR "Unknown platform: module name: ${target}")
    endif()


    get_property(${target}_COMPILE_OPTIONS TARGET ${target} PROPERTY COMPILE_OPTIONS)

    set(TARGET_COMPILE_OPTIONS ${${target}_COMPILE_OPTIONS})

    message(STATUS "Compiler options for ${target} ${TARGET_COMPILE_OPTIONS}")

    set_target_properties(
            ${target}
            PROPERTIES
            CXX_STANDARD ${CMAKE_CXX_STANDARD}
            CXX_STANDARD_REQUIRED ON
            CXX_EXTENSIONS ON
            COMPILE_OPTIONS "${TARGET_COMPILE_OPTIONS}"
    )
endfunction()
