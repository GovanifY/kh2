#pragma once

#include "../common/types.h"

namespace Tz {

class MCard {
public:
    static bool isFindSystem();
    static void* GetMCInfo();
    static u32 ClearFileInfo();
    static u32 ChgWorldName(s32);
    static void SetSystemMode(s32);
    static u32 ChgDir(s32);
    static u32 MakeDir();
    static void SetSlot(s32);
    static s32 GetSlot();
    static void SetPos(s32);
};

}  // namespace Tz

