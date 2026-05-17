#include "target.hpp"

namespace YS {



extern "C" u32 func_0019ba60(u32);

u32 TARGET::is_valid() const {
    register u32 s0 = 0u;
    if (*(u32*)((u32)this + (s32)(8)) != 0u) goto Lset;
    if (func_0019ba60(*(u32*)((u32)this + (s32)(0))) == 0u) goto Lret;
Lset:
    s0 = 1u;
Lret:
    return s0;
}

}  // namespace YS
