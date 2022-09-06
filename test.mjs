import test from 'brittle'

import { crc32 } from './index.js'

test('crc32', (t) => {
  t.is(crc32(Buffer.from('')), 0)
})
