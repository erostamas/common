set(TARGET et_something)
add_library(${TARGET} SHARED
	Something.cc
)

target_link_libraries(${TARGET}
	boost_filesystem
)

INSTALL(TARGETS ${TARGET}
	DESTINATION /usr/lib/erostamas/
	PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/Something.h
	DESTINATION /usr/include/erostamas/
	PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)

add_executable(test_something test_something.cc)

target_link_libraries(test_something et_something)