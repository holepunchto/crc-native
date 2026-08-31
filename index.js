const binding = require('#binding')

exports.crc32 = function crc32(buffer) {
  return binding.crc32(buffer)
}
