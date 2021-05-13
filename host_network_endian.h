#pragma once

#if defined(_WIN32)

#include <winsock2.h>

#define hton16(x) htons(x)
#define ntoh16(x) ntohs(x)

#define hton32(x) htonl(x)
#define ntoh32(x) ntohl(x)

#define hton64(x) htonll(x)
#define ntoh64(x) ntohll(x)

#elif defined(__linux__) || defined(__CYGWIN__)

#include <endian.h>

#define hton16(x) htobe16(x)
#define ntoh16(x) be16toh(x)

#define hton32(x) htobe32(x)
#define ntoh32(x) be32toh(x)

#define hton64(x) htobe64(x)
#define ntoh64(x) be64toh(x)

#elif defined(__APPLE__)

#include <libkern/OSByteOrder.h>

#define hton16(x) OSSwapHostToBigInt16(x)
#define ntoh16(x) OSSwapBigToHostInt16(x)

#define hton32(x) OSSwapHostToBigInt32(x)
#define ntoh32(x) OSSwapBigToHostInt32(x)

#define hton64(x) OSSwapHostToBigInt64(x)
#define ntoh64(x) OSSwapBigToHostInt64(x)

#elif defined(__OpenBSD__)

#include <sys/endian.h>

#define hton16(x) htobe16(x)
#define ntoh16(x) be16toh(x)

#define hton32(x) htobe32(x)
#define ntoh32(x) be32toh(x)

#define hton64(x) htobe64(x)
#define ntoh64(x) be64toh(x)

#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)

#include <sys/endian.h>

#define hton16(x) htobe16(x)
#define ntoh16(x) betoh16(x)

#define hton32(x) htobe32(x)
#define ntoh32(x) betoh32(x)

#define hton64(x) htobe64(x)
#define ntoh64(x) betoh64(x)

#else

#error platform not supported

#endif

/**********************************************************************
 *                                cpp                                 *
 **********************************************************************/

#ifdef __cplusplus

#include <cstdint>

#include <type_traits>

template <typename T, typename std::enable_if<sizeof(T) == 1, int>::type = 0>
T hton(const T &t) {
    return t;
}

template <typename T, typename std::enable_if<sizeof(T) == 2, int>::type = 0>
T hton(const T &t) {
    return static_cast<T>(hton16(static_cast<uint16_t>(t)));
}

template <typename T, typename std::enable_if<sizeof(T) == 4, int>::type = 0>
T hton(const T &t) {
    return static_cast<T>(hton32(static_cast<uint32_t>(t)));
}

template <typename T, typename std::enable_if<sizeof(T) == 8, int>::type = 0>
T hton(const T &t) {
    return static_cast<T>(hton64(static_cast<uint64_t>(t)));
}

template <typename T, typename std::enable_if<sizeof(T) == 1, int>::type = 0>
T ntoh(const T &t) {
    return t;
}

template <typename T, typename std::enable_if<sizeof(T) == 2, int>::type = 0>
T ntoh(const T &t) {
    return static_cast<T>(ntoh16(static_cast<uint16_t>(t)));
}

template <typename T, typename std::enable_if<sizeof(T) == 4, int>::type = 0>
T ntoh(const T &t) {
    return static_cast<T>(ntoh32(static_cast<uint32_t>(t)));
}

template <typename T, typename std::enable_if<sizeof(T) == 8, int>::type = 0>
T ntoh(const T &t) {
    return static_cast<T>(ntoh64(static_cast<uint64_t>(t)));
}

#endif
