#include "../common/types.h"

// Agent R46m-4 (2026-10-23): FUN_0031f940 (SLPM_666.75), 40 bytes.
// Code: a0 = word at a0+24; calls the virtual slot 4 (word at +16 of the vtable) on a0, with a0 as the argument.
// Guess: a forwarder that calls a method on an object held at offset 24.
// Plain C matches; no flags needed (size is a multiple of 8).
typedef unsigned int u32;

void func_0031f940(u32 a0) {
    u32* obj = *(u32**)((unsigned char*)a0 + 24);
    u32* vt = *(u32**)obj;
    ((void (*)(u32*))vt[4])(obj);
}
