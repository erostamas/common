set (TESTNAME test_config)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)

add_executable(${TESTNAME}
    TestConfig.cc)

target_link_libraries(${TESTNAME}
    gtest
	gtest_main
	pthread
	et_config)

ADD_TEST(${TESTNAME} ${CMAKE_CURRENT_BINARY_DIR}/${TESTNAME})