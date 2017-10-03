cmake_minimum_required(VERSION 3.5)
project(nanogui_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(3rdParty/nanogui)
include_directories(3rdParty/nanogui/include)
include_directories(${NANOGUI_EXTRA_INCS})
add_definitions(${NANOGUI_EXTRA_DEFS})

add_subdirectory(Common)

SOURCE_GROUP(CORE 		FILES ${CORE_SRCS})
SOURCE_GROUP(GEOMETRY 	FILES ${GEOMETRY_SRCS})
SOURCE_GROUP(LOADERS 	FILES ${LOADERS_SRCS})
SOURCE_GROUP(RENDERERS 	FILES ${RENDERERS_SRCS})
SOURCE_GROUP(UTILITIES 	FILES ${UTILITIES_SRCS})
SOURCE_GROUP(WINDOWMGT 	FILES ${WINDOWMGT_SRCS})

add_executable(SliceBasedVolumeRendering
	SliceBasedVolumeRendering/Source/Source.cpp
	${ALL_AT_FRAMEWORK_SRC}
)
target_link_libraries(SliceBasedVolumeRendering
	nanogui ${NANOGUI_EXTRA_LIBS}
	assimp
)

add_custom_command(TARGET SliceBasedVolumeRendering POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${PROJECT_SOURCE_DIR}/Common/StandardShapes ${PROJECT_BINARY_DIR}/Common/StandardShapes
					   COMMENT "Copying standard shapes")