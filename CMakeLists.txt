cmake_minimum_required(VERSION 2.8)

project(SimpleEngine)

include_directories("${PROJECT_SOURCE_DIR}/include/")

include_directories("${PROJECT_SOURCE_DIR}/lib/pugixml/src")

include_directories("${PROJECT_SOURCE_DIR}/lib/Box2D")

file(GLOB_RECURSE files RELATIVE "${PROJECT_SOURCE_DIR}" "src/*/*.cpp")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Os")

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")

SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "~/lib/")

add_library(SimpleEngine SHARED ${files})