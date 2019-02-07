CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(agenda)
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
SET (source_dir "${PROJECT_SOURCE_DIR}/src")
#SET( CMAKE_EXPORT_COMPILE_COMMANDS ON   )

#FILE(GLOB source_files "${source_dir}/*.cpp")
FILE(GLOB source_files 

"${source_dir}/test.cpp"
"${source_dir}/Date.cpp"
"${source_dir}/Time.cpp"
"${source_dir}/*.h"
#"${source_dir}/Time.cpp"
#"${source_dir}/Event.cpp"
#"${source_dir}/Util.cpp"
#"${source_dir}/Tasks.cpp"
)

ADD_EXECUTABLE (agenda ${source_files})
