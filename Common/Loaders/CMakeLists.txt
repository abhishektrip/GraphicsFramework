cmake_minimum_required(VERSION 3.0)

file(GLOB_RECURSE SRC_FILES "*.cpp" "*.h")

SET(LOADERS_SRC_FILES ${SRC_FILES} PARENT_SCOPE)

SET(LOADERS_INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)