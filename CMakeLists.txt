cmake_minimum_required(VERSION 3.25)

project(crc_native C)

include(bare)
include(napi)

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

bare_include_directories(compat NAPI)

target_include_directories(
  ${crc_native_node}
  PRIVATE
    ${compat}
)

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
