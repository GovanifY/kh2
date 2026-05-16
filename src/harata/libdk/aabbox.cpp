#include "types.h"

namespace kn {
class FVector;
}

namespace dk {
class Line;
class Aabbox {
public:
    Aabbox(f32, f32, f32, f32, f32, f32);
    Aabbox(kn::FVector const&, kn::FVector const&);
    Aabbox(Line const&);
    void set(kn::FVector const&, kn::FVector const&);
    void set(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
};

struct AabboxLayout {
    f32 v0, v1, v2, v3, v4, v5;
};

struct FVectorLayout {
    f32 x, y, z;
};

Aabbox::Aabbox(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    *(volatile f32*)((u32)this + 0) = a;
    *(volatile f32*)((u32)this + 4) = b;
    *(volatile f32*)((u32)this + 8) = c;
    *(volatile f32*)((u32)this + 12) = d;
    *(volatile f32*)((u32)this + 16) = e;
    *(volatile f32*)((u32)this + 20) = f;
}

Aabbox::Aabbox(kn::FVector const& a, kn::FVector const& b) { set(a, b); }

Aabbox::Aabbox(Line const& line) {
    set(*reinterpret_cast<kn::FVector const*>(&line),
        *reinterpret_cast<kn::FVector const*>(reinterpret_cast<u8 const*>(&line) + 16u));
}

void Aabbox::set(kn::FVector const& a, kn::FVector const& b) {
    FVectorLayout const* va = reinterpret_cast<FVectorLayout const*>(&a);
    FVectorLayout const* vb = reinterpret_cast<FVectorLayout const*>(&b);
    AabboxLayout* l = reinterpret_cast<AabboxLayout*>(this);

    if (va->x < vb->x) {
        l->v0 = va->x;
        l->v3 = vb->x;
    } else {
        l->v0 = vb->x;
        l->v3 = va->x;
    }

    if (va->y < vb->y) {
        l->v1 = va->y;
        l->v4 = vb->y;
    } else {
        l->v1 = vb->y;
        l->v4 = va->y;
    }

    if (va->z < vb->z) {
        l->v2 = va->z;
        l->v5 = vb->z;
    } else {
        l->v2 = vb->z;
        l->v5 = va->z;
    }
}

void Aabbox::set(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    AabboxLayout* l = reinterpret_cast<AabboxLayout*>(this);
    l->v0 = a;
    l->v1 = b;
    l->v2 = c;
    l->v3 = d;
    l->v4 = e;
    l->v5 = f;
}
}  // namespace dk
