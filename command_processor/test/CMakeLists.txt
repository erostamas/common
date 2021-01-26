set (TESTNAME test_command_processor)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)

add_executable(${TESTNAME}
    TestCommandProcessor.cc
    TestMessageReceiver.cc
    TestStringCommandAdapter.cc)

target_link_libraries(${TESTNAME}
    gmock_main
    gmock
    gtest
    pthread
    et_command_processor)

ADD_TEST(${TESTNAME} ${CMAKE_CURRENT_BINARY_DIR}/${TESTNAME})