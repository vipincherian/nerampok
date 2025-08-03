// bit_utils.h
#ifndef UTILS_H
#define UTILS_H

namespace util {

/**
 * @brief Return a 64-bit mask with only the rightmost zero bit of `u` set.
 *        If `u` has no zero bits (i.e. equals UINT64_MAX), returns zero.
 *
 * @code
 * mask = (~u) & (u + 1);
 * @endcode
 *
 * This trick isolates the least significant zero-bit in O(1) time, using only
 * two’s-complement arithmetic and bit ops
 * :contentReference[oaicite:3]{index=3}.
 */
unsigned long long rightmostZeroMask(unsigned long long u) noexcept;

/**
 * @brief Return the index (0 = LSB) of the rightmost zero-bit in `u`.
 *        Returns -1 if `u == UINT64_MAX` (no zero bit).
 *
 * Uses the mask from rightmost_zero_mask and applies a trailing-zero count:
 *  - On GCC/Clang: __builtin_ctzll(mask)
 *  - On MSVC: use _BitScanForward64
 *  - Otherwise: simple fallback loop (detects mask==0 first)
 *
 * If mask ≠ 0, the index is guaranteed to be in [0 … 63].
 */
int rightmostZeroIndex(unsigned long long u) noexcept;

}  // namespace util

#endif  // BIT_UTILS_H_