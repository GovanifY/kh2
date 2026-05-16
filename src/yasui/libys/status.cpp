#include "types.h"

namespace YS {

extern u32 D_01c61958 asm("D_01c61958");
extern f32 D_01c61964 asm("D_01c61964");
extern u32 D_01c61968 asm("D_01c61968");
extern u32 D_01c6196c asm("D_01c6196c");

class STATUS {
public:
    static u32 GetMode();
    static u32 IsBattleMode();
    static void SetPrizeRatio(f32);
    static f32 GetLockOnRatio();
    static f32 GetLockOutRange();
};

u32 STATUS::GetMode() { return D_01c61958; }

u32 STATUS::IsBattleMode() { return (D_01c61958 != 0); }

void STATUS::SetPrizeRatio(f32 value) { D_01c61964 = value; }

f32 STATUS::GetLockOnRatio() { return *(f32*)&D_01c61968; }

f32 STATUS::GetLockOutRange() { return *(f32*)&D_01c6196c; }

}  // namespace YS
