#ifndef KH2_SRC_TOZAWA_UNITLOAD_HPP
#define KH2_SRC_TOZAWA_UNITLOAD_HPP

#include "types.h"

namespace Tz {

class UnitLoad {
public:
    u64 BackReadFace(void);
    u64 BackReadItem(void);
    u32 isReading(void);
    void ReadCallback(void* a0, u32 a1, void* a2);
    void Exit(void);
    void DeleteEntryAll(void);
    void ResetBuffer(void);
    void InitLoadBuffer(void);
    u64 isLoad(s32 a0);
    u64 isEntry(s32 a0);
    void SetLoadData(short* a0, s32 a1);
    u32 GetAddr(s32 a0);
};

}  // namespace Tz

#endif
