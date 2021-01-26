set(TARGET et_logging)
add_library(${TARGET} SHARED
	Logging.cc
)

target_link_libraries(${TARGET}
	boost_log
	boost_log_setup
)

INSTALL(TARGETS ${TARGET}
	DESTINATION /usr/lib/erostamas/
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Logging.h
	DESTINATION /usr/include/erostamas/
	PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)

add_subdirectory(test)

enable_testing()
