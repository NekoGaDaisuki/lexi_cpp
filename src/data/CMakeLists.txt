add_library(lexi-cpp-data SHARED List.cpp)
add_executable(test-list TestList.cpp)
target_link_libraries(test-list lexi-cpp-data ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

