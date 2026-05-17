#pragma once

#include "../common/types.h"

namespace Tz {

class ItemStat {
public:
    s32 GetFontSeq(s32);
    void UpdateNowStat(s32, s32, s32, s32, s32);
    void* ClearSeq();
    void Clear();
};

}  // namespace Tz

