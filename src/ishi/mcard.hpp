#pragma once

#include "../common/types.h"

namespace YI {

    class MCARD {
    public:
        static u32 isIdle();
        static u32 GetResultInfoRoot();
        static u32 GetResultChangeDir();
        static u32 GetConnectionStatus(s32, s32);
        static u32 GetFileTableMax(s32, s32);
    };

}  // namespace YI

