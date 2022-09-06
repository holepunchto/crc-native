#include <crc.h>
#include <napi-macros.h>
#include <node_api.h>
#include <stdio.h>

NAPI_METHOD(crc32_napi) {
  NAPI_ARGV(1);
  NAPI_ARGV_BUFFER_CAST(uint8_t *, buf, 0);

  printf("%.*s %lu\n", (int) buf_len, buf, buf_len);

  NAPI_RETURN_UINT32(crc32(buf, buf_len));
}

NAPI_INIT() {
  NAPI_EXPORT_FUNCTION(crc32_napi);
}
