include_directories(../)

add_executable(udp_receiver_test
    udp_receiver_test.cc
)

target_link_libraries(udp_receiver_test
    et_udp
    pthread
)

add_executable(udp_sender_test
    udp_sender_test.cc
)

target_link_libraries(udp_sender_test
    et_udp
    pthread
)

add_executable(udp_echo_server
    udp_echo_server.cc
)

target_link_libraries(udp_echo_server
    et_udp
    pthread
)