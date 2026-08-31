#include <assert.h>
#include <bare.h>
#include <crc.h>
#include <js.h>
#include <stdint.h>

static js_value_t *
crc_native_crc32 (js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  uint8_t *buf;
  size_t len;
  err = js_get_typedarray_info(env, argv[0], NULL, (void **) &buf, &len, NULL, NULL);
  assert(err == 0);

  js_value_t *result;
  err = js_create_uint32(env, crc_u32(buf, len), &result);
  assert(err == 0);

  return result;
}

static js_value_t *
crc_native_exports (js_env_t *env, js_value_t *exports) {
  int err;

#define V(name, fn) \
  { \
    js_value_t *val; \
    err = js_create_function(env, name, -1, fn, NULL, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  V("crc32", crc_native_crc32)
#undef V

  return exports;
}

BARE_MODULE(crc_native, crc_native_exports)
