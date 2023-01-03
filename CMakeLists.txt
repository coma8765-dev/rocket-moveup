# !!! WARNING !!! AUTO-GENERATED FILE, PLEASE DO NOT MODIFY IT AND USE
# https://docs.platformio.org/page/projectconf/section_env_build.html#build-flags
#
# If you need to override existing CMake configuration or add extra,
# please create `CMakeListsUser.txt` in the root of project.
# The `CMakeListsUser.txt` will not be overwritten by PlatformIO.

cmake_minimum_required(VERSION 3.13)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

project("untitled" C CXX)

include(CMakeListsPrivate.txt)

include_directories(./lib/HC12)
include_directories(./lib/CommandBus)
include_directories(./lib/MultiServo)
include_directories(./.pio/libdeps/pro16MHzatmega328/Servo/src)
include_directories(./include/Servo/src)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeListsUser.txt)
include(CMakeListsUser.txt)
include_directories("./.pio/libdeps/pro16MHzatmega328")
endif()

add_custom_target(
    Production ALL
    COMMAND platformio -c clion run "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    Debug ALL
    COMMAND platformio -c clion debug "$<$<NOT:$<CONFIG:All>>:-e${CMAKE_BUILD_TYPE}>"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(Z_DUMMY_TARGET ${SRC_LIST} lib/MultiServo/MultiServo.cpp lib/MultiServo/MultiServo.h lib/HC12/HC12.cpp lib/HC12/HC12.h lib/CommandBus/CommandBus.cpp lib/CommandBus/CommandBus.h)