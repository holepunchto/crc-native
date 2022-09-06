import test from 'brittle'

import { crc32 } from './index.js'

import segfaultHandler from 'node-segfault-handler'

segfaultHandler.registerHandler()

test('crc32', (t) => {
  t.is(crc32(Buffer.from('abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh')), 0x6b64f5d)
})
