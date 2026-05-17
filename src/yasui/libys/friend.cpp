#include "friend.hpp"

namespace YS {

extern u32 D_01c60528 asm("D_01c60528");



u32 FRIEND::Get(s32 index) { return *(u32*)((u32)&D_01c60528 + ((u32)index << 2)); }

}  // namespace YS
