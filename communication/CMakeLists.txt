include_directories(./)

add_subdirectory(udp)

INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Message.h
	DESTINATION /usr/include/erostamas/
	PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)