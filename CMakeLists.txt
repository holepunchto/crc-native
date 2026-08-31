cmake_minimum_required(VERSION 3.25)

find_package(cmake-bare REQUIRED PATHS node_modules/cmake-bare)
find_package(cmake-fetch REQUIRED PATHS node_modules/cmake-fetch)
find_package(cmake-napi REQUIRED PATHS node_modules/cmake-napi)
find_package(cmake-npm REQUIRED PATHS node_modules/cmake-npm)

project(crc_native C)

bare_target(target)

if(target MATCHES "win32")
  add_compile_options(/MT$<$<CONFIG:Debug>:d>)
endif()

fetch_package("github:holepunchto/libcrc#9a0c969")

add_bare_module(crc_native_bare)

target_sources(
  ${crc_native_bare}
  PRIVATE
    binding.c
)

target_link_libraries(
  ${crc_native_bare}
  PRIVATE
    $<TARGET_OBJECTS:crc>
  PUBLIC
    crc
)

add_napi_module(crc_native_node)

target_sources(
  ${crc_native_node}
  PRIVATE
    binding.c
)

target_compile_definitions(
  ${crc_native_node}
  PRIVATE
    NAPI_VERSION=9
)

resolve_node_module(bare-compat-napi compat)

target_include_directories(
  ${crc_native_node}
  PRIVATE
    "${compat}/include"
)

target_link_libraries(
  ${crc_native_node}
  PRIVATE
    $<TARGET_OBJECTS:crc>
  PUBLIC
    crc
)
