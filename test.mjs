import test from 'brittle'

import { crc32 } from './index.js'

import SegfaultHandler from 'segfault-handler'

SegfaultHandler.registerHandler()

test('crc32', (t) => {
  t.is(crc32(Buffer.from('abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh')), 0x6b64f5d)
})
