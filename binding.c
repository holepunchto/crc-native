#include <crc.h>
#include <napi-macros.h>
#include <node_api.h>

NAPI_METHOD(crc32_napi) {
  NAPI_ARGV(1);
  NAPI_ARGV_BUFFER(buf, 0);

  NAPI_RETURN_UINT32(crc32((uint8_t *) buf, buf_len));
}

NAPI_INIT() {
  NAPI_EXPORT_FUNCTION(crc32_napi);
}
