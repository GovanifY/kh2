#include "types.h"

namespace dk {

extern u32 D_00347d58 asm("D_00347d58");

class TREASURE_INFO {
public:
    static u32 openEventInfo(s32);
    static u32 isEventInfoAllEnd();
    static u32 isEventInfoExist();
};

extern u32 D_00347d58 asm("D_00347d58");
extern "C" u32 func_00253180(u32, u32);

u32 TREASURE_INFO::openEventInfo(s32 a0) {
    u32 r4 = (u32)a0, r5 = (u32)-1;
    *(u32*)((u32)&D_00347d58 + (s32)(0)) = r4;
    r4 = 7u;
    return func_00253180(r4, r5);
}

u32 TREASURE_INFO::isEventInfoAllEnd() {
    u32 v = D_00347d58;
    return (v < 1u);
}

extern u8 D_00347d60 asm("D_00347d60");
extern "C" u32 dk_treasure_info_open_event_info(u32) asm("_Z16u_call4_00139d78jjjj");

u32 TREASURE_INFO::isEventInfoExist() {
    u32 r14 = *(u32*)((u32)&D_00347d60 + 0);
    u32 r2 = 0u;
    if (r14 != 0u) {
        r2 = dk_treasure_info_open_event_info(r14);
    }
    return r2;
}

}  // namespace dk
