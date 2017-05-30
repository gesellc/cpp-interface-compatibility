project(ApplicationTest)

add_subdirectory(lib/googletest-release-1.8.0)

add_executable(inventory_test
        inventory_test.cpp)

target_link_libraries(inventory_test gtest_main gmock_main)
target_link_libraries(inventory_test inventory_V_1_0_0 inventory_V_2_0_0)

#
# CTest
#

enable_testing()
add_test(inventory_ctest_001 inventory_test)
