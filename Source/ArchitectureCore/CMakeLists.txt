set(target ArchitectureCore)

add_library(${target} 
			STATIC 
			GeneratePointsController.cpp
			GeneratePointsModel.cpp
			${IncludeDir}/ArchitectureCore/GeneratePointsController.h
			${IncludeDir}/ArchitectureCore/GeneratePointsModel.h
			${IncludeDir}/Interfaces/IController.h
			${IncludeDir}/Interfaces/IModel.h
			${IncludeDir}/Interfaces/IRenderable.h
			${IncludeDir}/Domain/UIData.h
)

target_link_libraries(${target} PRIVATE Qt6::Core Async RenderHelpers Qt6::Gui)

include(CompilerOptions)
SetCompilerOptions(${PROJECT_NAME})
include(ClangTidyOptions)
UseClangTidy(${PROJECT_NAME})