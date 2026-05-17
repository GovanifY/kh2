#ifndef KH2_SRC_TOZAWA_CRC_HPP
#define KH2_SRC_TOZAWA_CRC_HPP

#include "types.h"

class ALLOCATOR;

namespace Tz {

class Crc {
public:
    void MakeTable();
    void CalcInit();
    void Init(ALLOCATOR*);
    void End();
    u32 Calc(uchar*, s32);
};

}  // namespace Tz

#endif
