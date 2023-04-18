cmake_minimum_required(VERSION 3.24)
project(SDIZO_PROJ_2)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp main.cpp)
add_executable(SDIZO_PROJ_2 ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
#add_subdirectory(tests)

target_link_libraries( SDIZO_PROJ_2
        SDIZO_GRAPHS
        )
