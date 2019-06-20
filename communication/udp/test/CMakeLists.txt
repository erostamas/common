include_directories(../)

add_executable(udp_receiver_test
    udp_receiver_test.cc
)

target_link_libraries(udp_receiver_test
    et_udp
)