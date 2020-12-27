project(Algorithm)
cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(DEBUG_PRINT ON)
set(TEST ON)

if (DEBUG_PRINT)
    add_definitions(-D_DEBUG_PRINT)
endif()

include_directories(.)
set(LIBS
    sort search)

foreach(item ${LIBS})
    include_directories(${item})
endforeach()

add_executable(testcode testcode.cpp)

if (TEST)
    add_definitions(-DTEST_ON)
    add_subdirectory(tests)
endif()