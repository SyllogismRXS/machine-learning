cmake_minimum_required (VERSION 2.6)
project (syllo)

set(ML_VERSION_MAJOR "0")
set(ML_VERSION_MINOR "0")
set(ML_VERSION_PATCH "0")
set(ML_VERSION "${ML_VERSION_MAJOR}.${ML_VERSION_MINOR}.${ML_VERSION_PATCH}")
set(ML_VERSION_DATE "2012.12.30")

# give ML 1 series a few more soversions
set(ML_SOVERSION "00")

set(CMAKE_INSTALL_PREFIX /usr/local)

# fetch all the local directories for generated code
get_filename_component(ML_LIB_DIR ./lib ABSOLUTE)
get_filename_component(ML_BIN_DIR ./bin ABSOLUTE)
get_filename_component(ML_INC_DIR ./include ABSOLUTE)
get_filename_component(ML_SRC_DIR ./src ABSOLUTE)
get_filename_component(ML_SHARE_DIR ./share ABSOLUTE)
get_filename_component(ML_BUILD_DIR ./build ABSOLUTE)
get_filename_component(ML_SCRIPTS_DIR ./scripts ABSOLUTE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_CXX_FLAGS "-g -Wall")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall") # -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall") # -fprofile-arcs -ftest-coverage")

set(EXECUTABLE_OUTPUT_PATH ${ML_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ML_LIB_DIR})

## set the cmake defaults for libraries and binaries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ML_LIB_DIR} CACHE PATH 
  "Output directory for the dynamic libraries" )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ML_BIN_DIR} CACHE PATH
  "Output directory for the binaries" )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ML_LIB_DIR} CACHE PATH 
  "Output directory for the static libraries (archives)" )

INSTALL(DIRECTORY ${ML_INC_DIR} DESTINATION ${CMAKE_INSTALL_PREFIX}
  FILES_MATCHING REGEX .*\\.h|.*\\.proto
)

#INSTALL(TARGETS ${} 
#  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
#  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
#)

install(DIRECTORY ${ML_LIB_DIR}/ 
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  )

## let cmake know where the headers are
include_directories(${ML_INC_DIR})

## copy to ml/include
file(GLOB_RECURSE INCLUDE_FILES RELATIVE ${ML_SRC_DIR} src/*.h src/*.hpp)
foreach(I ${INCLUDE_FILES})
  configure_file(${ML_SRC_DIR}/${I} ${ML_INC_DIR}/ml/${I} @ONLY)
endforeach()

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

#message("====>")
#message("${eigen3_INCLUDE_DIRS}")

#include_directories(${eigen_INCLUDE_DIR})
#include_directories(${EIGEN3_INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(share)
