const binding = require('node-gyp-build')(__dirname)

exports.crc32 = function crc32 (buffer) {
  return binding.crc32_napi(buffer)
}
