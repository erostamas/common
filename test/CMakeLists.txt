add_executable(test_config_and_logging
    test_config_and_logging.cc
)

target_link_libraries(test_config_and_logging
    et_logging
    et_config
)