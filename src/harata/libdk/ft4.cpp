#include "ft4.hpp"

namespace dk {
void Ft4Base::setRot(f32 v) { *(f32*)((u32)this + 272) = v; }
void Ft4Base::setCenterXY(s32 x, s32 y) {
    *(s32*)((u32)this + 276) = x;
    *(s32*)((u32)this + 280) = y;
}
void Ft4Base::setGsTex0(u64 v) { reinterpret_cast<Ft4BaseLayout*>(this)->gs_tex0 = v; }
void Ft4Base::setGsTest(u64 v) { reinterpret_cast<Ft4BaseLayout*>(this)->gs_test = v; }
void Ft4Base::setGsPrim(u64 v) { reinterpret_cast<Ft4BaseLayout*>(this)->gs_prim = v; }
}  // namespace dk
