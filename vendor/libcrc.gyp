{
  'targets': [{
    'target_name': 'libcrc',
    'type': 'static_library',
    'sources': [
      './libcrc/src/arm.c',
      './libcrc/src/endian.c',
      './libcrc/src/generic.c',
      './libcrc/src/lookup.c',
    ],
    'configurations': {
      'Debug': {
        'defines': ['DEBUG'],
      },
      'Release': {
        'defines': ['NDEBUG'],
      },
    },
    'xcode_settings': {
      'OTHER_CFLAGS': [
        '-O3',
      ]
    },
    'cflags': [
      '-O3',
    ],
  }]
}
