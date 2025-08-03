// bit_utils.cpp
#include "utils.h"

namespace util {

unsigned long long rightmostZeroMask(unsigned long long u) noexcept {
    // Isolate the rightmost zero bit:
    //   ~u flips bits; (u + 1) flips low-order trailing 1s to 0
    //   AND them to isolate only the mirrored zero bit
    return (~u) & (u + 1);
}

int rightmostZeroIndex(unsigned long long u) noexcept {
    unsigned long long mask = rightmostZeroMask(u);
    if (mask == 0) return -1;  // no zero bit found

    // Count trailing zeros to get the bit index. Behavior undefined if mask==0,
    // but we guard against that above.
    return static_cast<int>(__builtin_ctzll(mask));
}

}  // namespace util