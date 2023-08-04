cmake_minimum_required(VERSION 3.0.2)
project(MATLAB_codegen_example)

include_directories( include )
include_directories( ~/MATLAB/extern/include )

find_package(Eigen3 REQUIRED)

## Declare a C++ library
# file(GLOB LIB_FILES lib/*.c)
# add_library( LIB STATIC ${LIB_FILES})
find_library(LIB errorR lib)

add_executable( ${PROJECT_NAME} src/main.cpp )

target_link_libraries( ${PROJECT_NAME} ${LIB} Eigen3::Eigen)
