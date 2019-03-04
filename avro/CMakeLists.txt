# Find avro library
find_path (AVRO_CPP_INCLUDE Encoder.hh /usr/local/include/avro)
MESSAGE(${AVRO_CPP_INCLUDE})
find_file (AVRO_CPP_LIBRARY libavrocpp.so.1.8.2.0 /usr/local/lib/)
MESSAGE(${AVRO_CPP_LIBRARY})

if (${AVRO_CPP_INCLUDE} STREQUAL "AVRO_CPP_INCLUDE-NOTFOUND" OR ${AVRO_CPP_LIBRARY} STREQUAL "AVRO_CPP_LIBRARY-NOTFOUND")
	MESSAGE( FATAL_ERROR "Cannot find avro library")
else()
	MESSAGE("Found avro library")
	MESSAGE("Include dirs: " ${AVRO_CPP_INCLUDE})
	MESSAGE("Library: " ${AVRO_CPP_LIBRARY})
	include_directories(${AVRO_CPP_INCLUDE})
endif()

add_executable(avro_test
	main.cc
)

target_link_libraries(avro_test
	${AVRO_CPP_LIBRARY}
)

add_executable(avro_test_2
	main2.cc
)

target_link_libraries(avro_test_2
	${AVRO_CPP_LIBRARY}
)