cmake_minimum_required(VERSION 3.25)

find_package(cmake-bare REQUIRED PATHS node_modules/cmake-bare)
find_package(cmake-napi REQUIRED PATHS node_modules/cmake-napi)

project(crc_native C)

if(NOT TARGET crc)
  add_subdirectory(vendor/libcrc EXCLUDE_FROM_ALL)
endif()

add_bare_module(crc_native_bare)

target_sources(
  ${crc_native_bare}
  PRIVATE
    binding.c
  PUBLIC
    $<TARGET_OBJECTS:crc>
)

target_link_libraries(
  ${crc_native_bare}
  PUBLIC
    crc
)

add_napi_module(crc_native_node)

target_sources(
  ${crc_native_node}
  PRIVATE
    binding.c
  PUBLIC
    $<TARGET_OBJECTS:crc>
)

target_link_libraries(
  ${crc_native_node}
  PUBLIC
    crc
)
