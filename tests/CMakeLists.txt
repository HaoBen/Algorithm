include_directories(.)

# all test case files shoud be added here
set(TESTS_SRC 
    demo_test.cpp
)

# sub directory
set(TESTS_SRC_DIR leetcode search)

# for leetcode tests
set(leetcode array.cpp)

# for search tests
set(search search_test.cpp)

foreach(dir ${TESTS_SRC_DIR})
    foreach(src ${${dir}})
        list(APPEND TESTS_SRC ${dir}/${src})
    endforeach()
endforeach()


add_executable(run_test main.cpp ${TESTS_SRC})
