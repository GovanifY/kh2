#include "types.h"

namespace WORLD {

extern u32 D_0033cbb8 asm("D_0033cbb8");

u32 GetName(s32 world_id) { return *(u32*)((u32)&D_0033cbb8 + ((u32)world_id << 2)); }

}  // namespace WORLD
