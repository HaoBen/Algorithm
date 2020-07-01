project(Algorithm)
cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LIBS
    sort)

include_directories(common)

foreach(item ${LIBS})
    #add_subdirectory(${item})
    include_directories(${item})
endforeach()

if (GTEST)
    add_subdirectory(test)
endif()

#add_executable(example example.cpp)
#target_link_libraries(example ${LIBS})
#add_test(NAME dddd COMMAND example)
