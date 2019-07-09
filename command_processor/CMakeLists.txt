include_directories(${PROJECT_SOURCE_DIR}/communication)

set(TARGET et_command_processor)
add_library(${TARGET} SHARED
    UdpMessageReceiver.cc
    CommandProcessor.cc
)

target_link_libraries(${TARGET}
	${BOOST_LIBS}
	et_logging
    et_udp
)

INSTALL(TARGETS ${TARGET}
	DESTINATION /usr/lib/erostamas/
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

INSTALL(FILES CommandProcessor.h ICommand.h ICommandAdapter.h IMessageReceiver.h UdpMessageReceiver.h
	DESTINATION /usr/include/erostamas/
	PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)

add_subdirectory(test)
