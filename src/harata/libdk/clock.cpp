#include "clock.hpp"

namespace dk {



extern "C" u32 func_001058e8(...);
extern "C" u32 func_0014ca80(...);

u32 Clock::getPlayTimeToHMSMS(u32& a0, u32& a1, u32& a2, u32& a3) {
    u32 s0 = (u32)&a0;
    u32 s1 = (u32)&a1;
    u32 s2 = (u32)&a2;
    u32 s3 = (u32)&a3;
    u32 v0 = func_001058e8();
    return func_0014ca80(*(u32*)(v0 + 9284), s0, s1, s2, s3);
}

}  // namespace dk
