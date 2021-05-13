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
