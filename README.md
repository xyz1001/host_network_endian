# Host Network Endian

## Introduction

This simple library is only used to convert between host and network endian.

## Features

- Support C and C++
- Cross platform
- Light-weight
- Header only

## Usage

- Place `endian.h` in your system wide or project's include directory. Then include this header.

## Example

C language:

``` c
#include <assert.h>
#include <stdint.h>

#include "../host_network_endian.h"

int main() {
    uint16_t u16 = 0x001f;
    uint32_t u32 = 0x0000001f;
    uint64_t u64 = 0x000000000000001f;

    assert(hton16(u16) == 0x1f00);
    assert(hton32(u32) == 0x1f000000);
    assert(hton64(u64) == 0x1f00000000000000);

    assert(ntoh16(hton16(u16)) == u16);
    assert(ntoh32(hton32(u32)) == u32);
    assert(ntoh64(hton64(u64)) == u64);

    return 0;
}
```

C++ language:

``` cpp
#include <cassert>
#include <cstdint>

#include "../host_network_endian.h"

int main() {
    uint16_t u16 = 0x001f;
    uint32_t u32 = 0x0000001f;
    uint64_t u64 = 0x000000000000001f;

    assert(hton(u16) == 0x1f00);
    assert(hton(u32) == 0x1f000000);
    assert(hton(u64) == 0x1f00000000000000);

    assert(ntoh(hton(u16)) == u16);
    assert(ntoh(hton(u32)) == u32);
    assert(ntoh(hton(u64)) == u64);

    return 0;
}
```

## License

MIT License

Copyright (c) 2021 xyz1001

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
