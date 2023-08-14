#include "posit.h"

namespace posit {

#define P32 Posit<int32_t, 32, 2, uint32_t, PositSpec::WithNan>
#define P16 Posit<int16_t, 16, 2, uint16_t, PositSpec::WithNan>
#define P8 Posit<int8_t, 8, 2, uint8_t, PositSpec::WithNan>

template class P32;
template class P16;
template class P8;

template P32 P16::to_posit();
template P32 P8::to_posit();
template P16 P32::to_posit();
template P16 P8::to_posit();
template P8 P32::to_posit();
template P8 P16::to_posit();

template <class PX, class fixed_t, int frac>
void from_fixed(PX *out, fixed_t src) {
    using BE=typename PX::BackendT;
    new (out) PX(BE::template make_fixed<fixedtrait<fixed_t, sizeof(fixed_t) * 8, frac>>(src));
}

template <class PX, class fixed_t, int frac>
fixed_t to_fixed(PX *src) {
    return src->to_backend().template pack_xfixed<fixedtrait<fixed_t, sizeof(fixed_t) * 8, frac>>();
}

#define EXPAND_FROM_FIXED(PX) \
template void from_fixed<PX, uint8_t, 0>(PX *, uint8_t); \
template void from_fixed<PX, uint8_t, 1>(PX *, uint8_t); \
template void from_fixed<PX, uint8_t, 2>(PX *, uint8_t); \
template void from_fixed<PX, uint8_t, 3>(PX *, uint8_t); \
template void from_fixed<PX, uint8_t, 4>(PX *, uint8_t); \
template void from_fixed<PX, uint8_t, 5>(PX *, uint8_t); \
template void from_fixed<PX, uint8_t, 6>(PX *, uint8_t); \
template void from_fixed<PX, uint8_t, 7>(PX *, uint8_t); \
template void from_fixed<PX, uint8_t, 8>(PX *, uint8_t); \
\
template void from_fixed<PX, uint16_t, 0>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 1>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 2>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 3>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 4>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 5>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 6>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 7>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 8>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 9>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 10>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 11>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 12>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 13>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 14>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 15>(PX *, uint16_t); \
template void from_fixed<PX, uint16_t, 16>(PX *, uint16_t); \
\
template void from_fixed<PX, uint32_t, 0>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 1>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 2>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 3>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 4>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 5>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 6>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 7>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 8>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 9>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 10>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 11>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 12>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 13>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 14>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 15>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 16>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 17>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 18>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 19>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 20>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 21>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 22>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 23>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 24>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 25>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 26>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 27>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 28>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 29>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 30>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 31>(PX *, uint32_t); \
template void from_fixed<PX, uint32_t, 32>(PX *, uint32_t); \
\
template void from_fixed<PX, uint64_t, 0>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 1>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 2>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 3>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 4>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 5>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 6>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 7>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 8>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 9>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 10>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 11>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 12>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 13>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 14>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 15>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 16>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 17>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 18>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 19>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 20>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 21>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 22>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 23>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 24>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 25>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 26>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 27>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 28>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 29>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 30>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 31>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 32>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 33>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 34>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 35>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 36>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 37>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 38>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 39>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 40>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 41>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 42>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 43>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 44>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 45>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 46>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 47>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 48>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 49>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 50>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 51>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 52>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 53>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 54>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 55>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 56>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 57>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 58>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 59>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 60>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 61>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 62>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 63>(PX *, uint64_t); \
template void from_fixed<PX, uint64_t, 64>(PX *, uint64_t); \

#define EXPAND_TO_FIXED(PX) \
template uint8_t to_fixed<PX, uint8_t, 0>(PX *); \
template uint8_t to_fixed<PX, uint8_t, 1>(PX *); \
template uint8_t to_fixed<PX, uint8_t, 2>(PX *); \
template uint8_t to_fixed<PX, uint8_t, 3>(PX *); \
template uint8_t to_fixed<PX, uint8_t, 4>(PX *); \
template uint8_t to_fixed<PX, uint8_t, 5>(PX *); \
template uint8_t to_fixed<PX, uint8_t, 6>(PX *); \
template uint8_t to_fixed<PX, uint8_t, 7>(PX *); \
template uint8_t to_fixed<PX, uint8_t, 8>(PX *); \
\
template uint16_t to_fixed<PX, uint16_t, 0>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 1>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 2>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 3>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 4>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 5>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 6>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 7>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 8>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 9>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 10>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 11>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 12>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 13>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 14>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 15>(PX *); \
template uint16_t to_fixed<PX, uint16_t, 16>(PX *); \
\
template uint32_t to_fixed<PX, uint32_t, 0>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 1>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 2>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 3>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 4>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 5>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 6>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 7>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 8>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 9>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 10>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 11>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 12>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 13>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 14>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 15>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 16>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 17>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 18>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 19>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 20>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 21>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 22>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 23>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 24>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 25>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 26>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 27>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 28>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 29>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 30>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 31>(PX *); \
template uint32_t to_fixed<PX, uint32_t, 32>(PX *); \
\
template uint64_t to_fixed<PX, uint64_t, 0>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 1>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 2>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 3>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 4>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 5>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 6>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 7>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 8>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 9>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 10>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 11>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 12>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 13>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 14>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 15>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 16>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 17>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 18>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 19>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 20>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 21>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 22>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 23>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 24>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 25>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 26>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 27>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 28>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 29>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 30>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 31>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 32>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 33>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 34>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 35>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 36>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 37>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 38>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 39>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 40>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 41>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 42>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 43>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 44>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 45>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 46>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 47>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 48>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 49>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 50>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 51>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 52>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 53>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 54>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 55>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 56>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 57>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 58>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 59>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 60>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 61>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 62>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 63>(PX *); \
template uint64_t to_fixed<PX, uint64_t, 64>(PX *); \

EXPAND_FROM_FIXED(P8)
EXPAND_TO_FIXED(P8)
EXPAND_FROM_FIXED(P16)
EXPAND_TO_FIXED(P16)
EXPAND_FROM_FIXED(P32)
EXPAND_TO_FIXED(P32)

}
