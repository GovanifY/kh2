#include "types.h"

namespace Tz {

class ItemInfo {
public:
    static u32 GetEquipMax(s32);
    static u32 GetItemEmptyMsg(s32);
};

extern "C" u32 func_00257130(...);
extern "C" u32 func_002827e0(...);

u32 ItemInfo::GetEquipMax(s32 a0) {
    u32 arr[5];
    s32 i = 0;
    while (i < 5) {
        u32 v = func_00257130();
        v = func_002827e0(v, i);
        arr[i] = v;
        i = i + 1;
    }

    s32 sum = 0;
    i = 0;
    while (1) {
        sum += (s32)arr[i];
        if (a0 < sum) {
            break;
        }
        i = i + 1;
        if (i >= 5) {
            break;
        }
    }

    return (u32)i;
}

u32 ItemInfo::GetItemEmptyMsg(s32 a0) { return (u32)((s32)a0 + 4132); }

}  // namespace Tz
