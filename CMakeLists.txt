cmake_minimum_required(VERSION 3.0)
PROJECT(logging)

set(BOOST_ROOT /usr/include/boost)

# compiler and linker flags
if ((NOT CMAKE_CXX_FLAGS) OR (CMAKE_CXX_FLAGS MATCHES "^[ \t]*$"))
  set(CXX11_FLAG "-std=c++11")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.8.2")
      set(CXX11_FLAG "-std=c++0x")
  endif()
  set(CMAKE_CXX_FLAGS "-O3 -g ${CXX11_FLAG} -Werror -Wall -DBOOST_LOG_DYN_LINK -DNDEBUG -fPIC -Wno-unused-result -lpthread")
  if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    message("Coverage mode selected")
      set(CMAKE_CXX_FLAGS "-O0 -g ${CXX11_FLAG} -Werror -Wall -DBOOST_LOG_DYN_LINK -fPIC -fprofile-arcs -ftest-coverage -lpthread")
  endif()
  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
      set(CMAKE_CXX_FLAGS "-O0 -g ${CXX11_FLAG} -Werror -Wall -fPIC -lpthread")
  endif()
endif()

#3pp
set(BOOST_COMPONENTS log system thread)
set(BOOST_LIBS boost_log boost_system boost_thread)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost
	1.62.0
	REQUIRED
	COMPONENTS ${BOOST_COMPONENTS})

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARIES})
endif()

enable_testing()

include_directories(logging)
include_directories(config)
include_directories(communication/udp)

add_subdirectory(logging)
add_subdirectory(config)
add_subdirectory(communication)
add_subdirectory(command_processor)
#add_subdirectory(avro)
