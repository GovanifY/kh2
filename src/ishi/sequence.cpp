#include "sequence.hpp"

namespace YI {

u32 SEQUENCE::GetDrawMode() { return (*(u32*)((u32)this + 252) != 0); }

u32 SEQUENCE::GetPlayMode() {
    u32 v = *(u32*)((u32)this + 252);
    v = (u32)((s32)v + (-1));
    return (v < 2u);
}

}  // namespace YI
