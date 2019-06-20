set(TARGET et_udp)
add_library(${TARGET} SHARED
    UdpInterface.cc
    UdpReceiver.cc
    UdpSender.cc
)

target_link_libraries(${TARGET}
	${BOOST_LIBS}
	et_logging
)

INSTALL(TARGETS ${TARGET}
	DESTINATION /usr/lib/erostamas/
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/UdpInterface.h ${CMAKE_CURRENT_SOURCE_DIR}/UdpSender.h ${CMAKE_CURRENT_SOURCE_DIR}/UdpReceiver.h
	DESTINATION /usr/include/erostamas/
	PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)

add_subdirectory(test)
