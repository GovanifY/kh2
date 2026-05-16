#ifndef KH2_TYPES_H
#define KH2_TYPES_H

// SCE GCC 3.2 doesn't ship stdint.h — define types directly.
// R5900 is 32-bit ABI (EABI): int=32, long=64, ptr=32.
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long long   s64;
typedef float              f32;

// Scripting system value (from mangled names _ZN2YStrap*EP8BD_VALUE)
// Each BD_VALUE slot is 4 bytes; trap functions receive an array BD_VALUE*.
// bd[0].i = int arg/result, bd[0].f = float, bd[0].p = pointer.
union BD_VALUE {
    s32   i;
    f32   f;
    void* p;
    u32   u;
};
#endif // KH2_TYPES_H
