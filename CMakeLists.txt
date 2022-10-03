cmake_minimum_required(VERSION 3.10)

# Set the project name
project(template)
include(CTest)

set(CMAKE_CXX_STANDARD 14)


# define library called queue that can imported into other targets via
# 'target_link_libraries'
add_library(mymath src/max.c src/list.c)
target_include_directories(mymath PUBLIC include)

# add the exectuable
add_executable(main src/main.cpp)
target_link_libraries(main mymath)

# tests are added by declaring a target, in this case 'tests'. additional tests
# can be added by expanding the test cases in 'src/tests.cpp' or an additional
# target via 'add_executable'
enable_testing()
add_subdirectory(tests)

