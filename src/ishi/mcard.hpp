#ifndef KH2_SRC_ISHI_MCARD_HPP
#define KH2_SRC_ISHI_MCARD_HPP

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

#endif
