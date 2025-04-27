set(target RenderHelpers)

add_library(${target} 
			STATIC 
			BatchPointsRender.cpp
			AreaBatchRender.cpp
			CircleAreaBatchRender.cpp
			${IncludeDir}/Interfaces/IRenderable.h
			${IncludeDir}/Render/BatchPointsRender.h
			${IncludeDir}/Render/AreaBatchRender.h
			${IncludeDir}/Render/CircleAreaBatchRender.h
			${IncludeDir}/Domain/UIData.h
)

target_link_libraries(${target} PRIVATE Qt6::Core Qt6::Gui)

include(CompilerOptions)
SetCompilerOptions(${PROJECT_NAME})
include(ClangTidyOptions)
UseClangTidy(${PROJECT_NAME})