#pragma once

#include "../common/types.h"

struct Obj0015de58 {
    struct Vt0015de58 {
        void (*fn0)(Obj0015de58*);
        void (*fn4)(Obj0015de58*);
    } *vtbl;
    u8 flag4;
};

struct Obj001537f8 {
    struct Vt001537f8 {
        void (*fn0)(Obj001537f8*, u32);
        void (*fn4)(Obj001537f8*, u32);
    } *vtbl;
};

struct ObjCommon_001050c8 {
    struct VtCommon_001050c8 {
        u32 (*fn0)(ObjCommon_001050c8*, u32, u32);
        void (*fn4)(ObjCommon_001050c8*, u32);
    } *vtbl;
};

typedef ObjCommon_001050c8 Obj0015a810;
typedef ObjCommon_001050c8 Obj0015a850;
typedef ObjCommon_001050c8 Obj0015b4c0;

struct Obj001502e8 {
    struct Vt001502e8 {
        void (*fn0)(Obj001502e8*);
        void (*fn4)(Obj001502e8*);
        void (*fn8)(Obj001502e8*);
        void (*fn12)(Obj001502e8*);
        void (*fn10)(Obj001502e8*);
    } *vtbl;
};

struct Obj00152498 {
    u8 _pad[2892];
    u32 field_b4c;
};

struct Vt_001a07b0 {
    void (*fn)(u32, u32, u32);
};

struct V4_222a00 {
    u32 _[4];
};

struct VObj_00173270 {
    u32* vtbl;
};

struct Pair_0018acd8 {
    u64 x;
    u64 y;
} __attribute__((packed));

struct V4_00199938 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

struct C7F0_Obj {
    struct Vt_C7F0_Obj {
        void (*fn0)(C7F0_Obj*);
        void (*fn1)(C7F0_Obj*);
        void (*fn2)(C7F0_Obj*);
        void (*fn3)(C7F0_Obj*);
        void (*fn4)(C7F0_Obj*);
        void (*fn5)(C7F0_Obj*);
    } *vtbl;
};

struct C7F0_State {
    C7F0_Obj* obj;
};

struct C828_Obj {
    struct Vt_C828_Obj {
        void (*fn0)(C828_Obj*);
        void (*fn1)(C828_Obj*);
        void (*fn2)(C828_Obj*);
        void (*fn3)(C828_Obj*);
        void (*fn4)(C828_Obj*);
        void (*fn5)(C828_Obj*);
        void (*fn6)(C828_Obj*);
    } *vtbl;
};

struct C828_State {
    C828_Obj* obj;
};

struct C4B0_State;

struct C4B0_Obj {
    struct Vt_C4B0_Obj {
        void (*fn0)(C4B0_Obj*);
        void (*fn1)(C4B0_Obj*);
        void (*fn2)(C4B0_Obj*);
        void (*fn3)(C4B0_Obj*);
        void (*fn4)(C4B0_Obj*);
        void (*fn5)(C4B0_Obj*);
        void (*fn6)(C4B0_Obj*);
        void (*fn7)(C4B0_Obj*);
        void (*fn8)(C4B0_Obj*);
        void (*fn9)(C4B0_Obj*);
        void (*fn10)(C4B0_Obj*);
        void (*fn11)(C4B0_Obj*, C4B0_State*);
    } *vtbl;
};

struct C4B0_State {
    C4B0_Obj* obj;
};
