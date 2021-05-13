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
