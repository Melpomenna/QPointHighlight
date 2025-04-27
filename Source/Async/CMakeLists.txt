set(target Async)

add_library(${target}
	STATIC
	${IncludeDir}/Async/Context.h
	Context.cpp
)

include(CompilerOptions)
SetCompilerOptions(${PROJECT_NAME})
include(ClangTidyOptions)
UseClangTidy(${PROJECT_NAME})