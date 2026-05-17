#include "obj.hpp"

namespace kn {
class FMatrix;
}

namespace YS {



u32 OBJ::GetPlayer() {
    u32 b = (0x0035u << 16);
    return (u32)(*(u32*)((u32)b + (-5816)));
}

extern "C" void func_0016c460(u32, u32);

void OBJ::get_jump_height() {
    struct S {
        u32 w0;
        u32 w1;
        u32 w2;
        u32 w3;
    } sp;
    func_0016c460((u32)this, (u32)&sp);
}

u32 OBJ::get_appear_way() {
    u32 r15 = *(volatile u32*)((u32)this + 2076);
    u32 r2 = (u32)((s32)0u + (-1));
    if (r15 != 0u) {
        r2 = (u32)(*(u8*)((u32)r15 + 28));
    }
    return r2;
}

u32 OBJ::get_serial() {
    u32 r15 = *(volatile u32*)((u32)this + 2076);
    u32 r2 = 0u;
    if (r15 != 0u) {
        r2 = (u32)(*(u16*)((u32)r15 + 30));
    }
    return r2;
}

void OBJ::set_unit_arg(int idx, int value) {
    u32 r5 = (u32)(idx << 2);
    r5 = (u32)(r5 + (u32)this);
    *(u32*)((u32)r5 + 2076) = (u32)value;
}

extern "C" u32 func_001a7790(...);

u32 OBJ::is_culling() {
    u32 r2 = 0u;
    u32 r15 = *(volatile u32*)((u32)this + (s32)(2040));
    r15 = (u32)(r15 & 0x0400u);
    u32 r4 = (u32)((s32)(u32)this + (1856));
    if (r15 != 0u) {
        r2 = ((u32(*)(u32))func_001a7790)(r4);
    }
    return r2;
}

u32 OBJ::get_type() {
    u32 flags = *(u32*)((u32)this + 1416);
    flags &= 0x80u;
    u32 r = 0;
    if (flags == 0u) {
        u32 p = *(u32*)((u32)this + 8);
        r = *(u8*)((u32)p + 4);
    }
    return r;
}

u32 OBJ::get_entry_id() {
    u32 p = *(u32*)((u32)this + 8);
    return *(u32*)((u32)p + 0);
}

u32 OBJ::get_part_num() {
    u32 p = *(u32*)((u32)this + 8);
    return (u32)(*(u16*)((u32)p + 76));
}

u32 OBJ::get_sub_type() {
    u32 p = *(u32*)((u32)this + 8);
    return *(u8*)((u32)p + 5);
}

u32 OBJ::get_skeleton_num() {
    u32 p = *(u32*)((u32)this + 8);
    return *(u8*)((u32)p + 7);
}

u32 OBJ::get_ground() {
    u32 r14 = ((u32*)(u32)this)[3];
    u32 r15 = ((u32*)(u32)r14)[2];
    r15 = (u32)(r15 & 0x0020u);
    u32 r2 = (u32)((s32)0u + 18);
    if (r15 == 0u) {
        r2 = ((u32*)(u32)this)[402];
    }
    return r2;
}

u32 OBJ::is_xyzrot() {
    u32 v = *(u32*)((u32)this + 2040);
    v &= 0x0008u;
    return (v != 0);
}

u32 OBJ::can_capture_control() {
    u32 v = *(u32*)((u32)this + 352);
    v &= 0x0004u;
    return (v != 0);
}

u32 OBJ::is_ghost() {
    u32 v = *(u32*)((u32)this + 264);
    v &= 0x0400u;
    return (v != 0);
}

u32 OBJ::is_attach() {
    return (*(u32*)((u32)this + 1392) != 0);
}

u32 OBJ::is_leave() {
    u32 t6 = *(u32*)((u32)this + 264);
    u32 t7 = (u32)(0x0008u << 16);
    t7 = (u32)(t6 & t7);
    u32 v0 = 0u;
    if (t7 != 0u) goto L1;
    t7 = (u32)(0x1000u << 16);
    t7 = (u32)(t6 & t7);
    if (t7 == 0u) goto L0;
L1:
    v0 = 1u;
L0:
    return v0;
}


u32 OBJ::is_hover() {
    u32 p = *(u32*)((u32)this + 12);
    u32 v = *(u32*)((u32)p + 4);
    v ^= 0x6u;
    return (v < 1u);
}

void OBJ::attach_camera(kn::FMatrix* camera) {
    u32 v0 = *(u32*)((u32)this + 268);
    u32 v1 = *(u32*)((u32)this + 1896);
    *(u32*)((u32)this + 1936) = (u32)camera;
    *(u32*)((u32)this + 268) = v0 | 0x40u;
    *(u32*)((u32)this + 1896) = v1 | 0x1000u;
}

u32 OBJ::is_updown() {
    u32 p = *(u32*)((u32)this + 12);
    u32 v = *(u32*)((u32)p + 8);
    v &= 0x8u;
    return (0u < v);
}

u32 OBJ::IsKinoko(int v) {
    u32 r4 = (u32)v;
    r4 = (u32)((s32)r4 + (-1047));
    r4 = ((u32)r4 < 0x0000000du);
    u32 r2 = r4;
    return r2;
}

}  // namespace YS
