// BdExecVM — YS scripting VM interpreter loop.
// Offset 0x001da558, size 0x9a0 bytes.
// Mangled: _Z8BdExecVMP11_BD_PROCESSPP7BD_TRAPPFvS0_9BD_STATUSPvES5_
#include "types.h"

struct _BD_PROCESS {
    u8* code;
    s32 pc;
    s32* fsp;
};

struct BD_TRAP_ENTRY {
    void (*func)(BD_VALUE*);
    u16 argc;
    u16 flags;
};
typedef BD_TRAP_ENTRY BD_TRAP;
typedef s32 BD_STATUS;
typedef void (*FuncDef66)(_BD_PROCESS*, BD_STATUS, void*);

extern "C" {
void func_001da3d8(_BD_PROCESS* proc, u32 src);
void func_001da3f8(_BD_PROCESS* proc, void* dst);
u32 func_001da4d8(_BD_PROCESS* proc, u32 instr);
void func_002fdd68(void* dst, void* src, u32 size);
float func_002f8b00(float a, float b);
float func_002f8960(float x);
float func_002f87c0(float x);
}

extern float DAT_0036e690;
extern float DAT_0036e694;
extern float DAT_0036e698;

// Force andi reg,reg,0xffff zero-extension (original GCC 3.2 emits this; newer
// range analysis eliminates it as redundant after lhu).
static inline u32 bd_zext16(u32 x) {
    u32 r;
    asm("andi %0,%1,0xffff" : "=r"(r) : "r"(x));
    return r;
}

// Force the 3-instruction mask sequence the original GCC 3.2 emits for
// "instr & 0xffc0":  li tmp,-64 / and tmp,instr,tmp / andi tmp,tmp,0xffff
// (original's range analysis can't prove the and result fits in 16 bits).
static inline int bd_mask_copy_check(u32 instr) {
    int r;
    asm("addiu %0,$0,-64\n\t and %0,%1,%0\n\t andi %0,%0,0xffff"
        : "=r"(r) : "r"(instr));
    return r;
}

// Stack frame layout matching original: tos@+0, tos2@+4, gap@+8, args@+16, tmp_addr@+80, tmp_offset@+84
struct BdLocals {
    BD_VALUE tos;
    BD_VALUE tos2;
    u8       _gap[8];
    BD_VALUE args[16];
    u32      tmp_addr;
    s32      tmp_offset;
};

BD_STATUS BdExecVM(_BD_PROCESS* proc, BD_TRAP** traps, FuncDef66 callback,
                   void* userdata) {
    BD_STATUS status = 0;
    BdLocals L;

    do {
        int pc = proc->pc;
        u8* code = proc->code;
        u32 instr = *(u16*)(code + pc * 2 + 0x10);
        u16 op = instr & 0xf;
        proc->pc = pc + 1;
        if (op >= 12) {
            status = 5;
            goto loop_end;
        }

        switch (op) {
            case 0: {
                int mode = (instr >> 4) & 3;
                if (mode != 2) {
                    if (mode < 3) {
                        if (mode < 0) { status = 5; goto loop_end; }
                        int npc = proc->pc;
                        func_001da3d8(proc, (u32)(code + npc * 2 + 0x10));
                        proc->pc = proc->pc + 2;
                    } else {
                        if (mode != 3) { status = 5; goto loop_end; }
                        L.tmp_addr = func_001da4d8(proc, (u32)instr);
                        func_001da3d8(proc, L.tmp_addr);
                    }
                } else {
                    L.tmp_addr = func_001da4d8(proc, (u32)instr);
                    func_001da3d8(proc, (u32)&L.tmp_addr);
                }
                break;
            }

            case 1: {
                u32 addr = func_001da4d8(proc, (u32)instr);
                L.tmp_addr = addr;
                func_001da3f8(proc, (void*)L.tmp_addr);
                break;
            }

            case 2: {
                func_001da3f8(proc, &L.tmp_addr);
                {
                    int npc = proc->pc;
                    u8* code2 = proc->code;
                    u16 next = *(u16*)(code2 + npc * 2 + 0x10);
                    proc->pc = npc + 1;
                    u32 dst = func_001da4d8(proc, (u32)instr);
                    func_002fdd68((void*)dst, (void*)L.tmp_addr, (u32)next);
                }
                break;
            }

            case 3: {
                func_001da3f8(proc, &L.tmp_addr);
                {
                    int npc = proc->pc;
                    u8* code2 = proc->code;
                    u16 off = *(u16*)(code2 + npc * 2 + 0x10);
                    proc->pc = npc + 1;
                    u32 ptr = L.tmp_addr + (u32)off;
                    L.tmp_addr = ptr;
                    func_001da3d8(proc, ptr);
                }
                break;
            }

            case 4: {
                func_001da3f8(proc, &L.tos);
                func_001da3f8(proc, &L.tmp_addr);
                {
                    if (!bd_mask_copy_check(instr)) {
                        __builtin_memcpy((void*)L.tmp_addr, &L.tos, sizeof(u32));
                    } else {
                        u32 cnt = (u16)instr >> 6;
                        func_002fdd68((void*)L.tmp_addr, (void*)L.tos.u, cnt);
                    }
                }
                break;
            }

            case 5: {
                func_001da3f8(proc, &L.tos);
                int mode5 = (instr >> 4) & 3;
                u16 sub5 = instr >> 6;
                if (mode5 == 1) {
                    if (sub5 >= 12) {
                        status = 5;
                        func_001da3d8(proc, (u32)&L.tos);
                        break;
                    }
                    switch (sub5) {
                        case 0:
                            status = 5;
                            func_001da3d8(proc, (u32)&L.tos);
                            goto loop_end;
                        case 1:
                            L.tos.i = (s32)L.tos.f;
                            break;
                        case 2:
                            L.tos.f = -L.tos.f;
                            break;
                        case 3:
                        case 4:
                            status = 5;
                            func_001da3d8(proc, (u32)&L.tos);
                            goto loop_end;
                        case 5:
                            L.tos.f = -(L.tos.f < 0.0f ? -L.tos.f : L.tos.f);
                            break;
                        case 6:
                            L.tos.i = (L.tos.f < 0.0f) ? 1 : 0;
                            break;
                        case 7:
                            L.tos.i = (L.tos.f <= 0.0f) ? 1 : 0;
                            break;
                        case 8:
                            L.tos.i = (L.tos.f == 0.0f) ? 1 : 0;
                            break;
                        case 9:
                            L.tos.i = (L.tos.f != 0.0f) ? 1 : 0;
                            break;
                        case 10:
                            L.tos.i = (L.tos.f >= 0.0f) ? 1 : 0;
                            break;
                        case 11:
                            L.tos.i = (L.tos.f > 0.0f) ? 1 : 0;
                            break;
                        default:
                            status = 5;
                            func_001da3d8(proc, (u32)&L.tos);
                            goto loop_end;
                    }
                    func_001da3d8(proc, (u32)&L.tos);
                } else if (mode5 == 0) {
                    if (sub5 >= 12) {
                        status = 5;
                        func_001da3d8(proc, (u32)&L.tos);
                        break;
                    }
                    switch (sub5) {
                        case 0:
                            L.tos.f = (float)L.tos.i;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        case 1:
                            status = 5;
                            func_001da3d8(proc, (u32)&L.tos);
                            goto loop_end;
                        case 2:
                            L.tos.i = -L.tos.i;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        case 3:
                            L.tos.i = ~L.tos.i;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        case 4:
                        case 8:
                            L.tos.i = (L.tos.i == 0) ? 1 : 0;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        case 5:
                            L.tos.i = (L.tos.i < 0) ? -L.tos.i : L.tos.i;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        case 6:
                            L.tos.i = (u32)L.tos.i >> 31;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        case 7:
                            L.tos.i = (L.tos.i <= 0) ? 1 : 0;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        case 9:
                            L.tos.i = (L.tos.i != 0) ? 1 : 0;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        case 10:
                            L.tos.i = (~L.tos.i >> 31) & 1;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        case 11:
                            L.tos.i = (L.tos.i > 0) ? 1 : 0;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        default:
                            status = 5;
                            func_001da3d8(proc, (u32)&L.tos);
                            goto loop_end;
                    }
                } else {
                    status = 5;
                    func_001da3d8(proc, (u32)&L.tos);
                }
                break;
            }

            case 6: {
                func_001da3f8(proc, &L.tos2);
                func_001da3f8(proc, &L.tos);
                {
                    int mode6 = (instr >> 4) & 3;
                    u16 sub6 = instr >> 6;
                    if (mode6 == 1) {
                        if (sub6 >= 5) {
                            status = 5;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        }
                        switch (sub6) {
                            case 0:
                                L.tos.f = L.tos.f + L.tos2.f;
                                break;
                            case 1:
                                L.tos.f = L.tos.f - L.tos2.f;
                                break;
                            case 2:
                                L.tos.f = L.tos.f * L.tos2.f;
                                break;
                            case 3:
                                L.tos.f = L.tos.f / L.tos2.f;
                                break;
                            case 4:
                                L.tos.f = func_002f8b00(L.tos.f, L.tos2.f);
                                break;
                            default:
                                status = 5;
                                func_001da3d8(proc, (u32)&L.tos);
                                goto loop_end;
                        }
                        func_001da3d8(proc, (u32)&L.tos);
                    } else if (mode6 == 0) {
                        if (sub6 >= 12) {
                            status = 5;
                            func_001da3d8(proc, (u32)&L.tos);
                            break;
                        }
                        switch (sub6) {
                            case 0:
                                L.tos.i = L.tos.i + L.tos2.i;
                                break;
                            case 1:
                                L.tos.i = L.tos.i - L.tos2.i;
                                break;
                            case 2:
                                L.tos.i = L.tos.i * L.tos2.i;
                                break;
                            case 3:
                                L.tos.i = L.tos.i / L.tos2.i;
                                break;
                            case 4:
                                L.tos.i = L.tos.i % L.tos2.i;
                                break;
                            case 5:
                                L.tos.i = L.tos.i & L.tos2.i;
                                break;
                            case 6:
                                L.tos.i = L.tos.i | L.tos2.i;
                                break;
                            case 7:
                                L.tos.i = L.tos.i ^ L.tos2.i;
                                break;
                            case 8:
                                L.tos.i = L.tos.i << L.tos2.i;
                                break;
                            case 9:
                                L.tos.i = L.tos.i >> L.tos2.i;
                                break;
                            case 10:
                                L.tos.i = (L.tos.i != 0 && L.tos2.i != 0) ? 1 : 0;
                                break;
                            case 11:
                                L.tos.i = (L.tos.i != 0 || L.tos2.i != 0) ? 1 : 0;
                                break;
                            default:
                                status = 5;
                                func_001da3d8(proc, (u32)&L.tos);
                                goto loop_end;
                        }
                        func_001da3d8(proc, (u32)&L.tos);
                    } else {
                        status = 5;
                        func_001da3d8(proc, (u32)&L.tos);
                    }
                }
                break;
            }

            case 7: {
                int jpc = proc->pc;
                u8* jcode = proc->code;
                s16 off = *(s16*)(jcode + jpc * 2 + 0x10);
                proc->pc = jpc + 1;
                L.tmp_offset = (s32)off;
                int sub7 = instr >> 6;
                if (sub7 == 0) {
                    proc->pc = proc->pc + (s32)off;
                } else if (sub7 == 1) {
                    func_001da3f8(proc, &L.tos);
                    if (!L.tos.i) {
                        proc->pc = proc->pc + (s32)off;
                    }
                } else if (sub7 == 2) {
                    func_001da3f8(proc, &L.tos);
                    if (L.tos.i) {
                        proc->pc = proc->pc + (s32)off;
                    }
                } else {
                    status = 5;
                }
                break;
            }

            case 8: {
                int cpc = proc->pc;
                u8* ccode = proc->code;
                s32 argc8 = instr >> 6;
                s16 foff = *(s16*)(ccode + cpc * 2 + 0x10);
                proc->pc = cpc + 1;
                L.tmp_offset = (s32)foff;
                s32* fsp = proc->fsp + argc8;
                proc->fsp = fsp;
                fsp[-1] = proc->pc;
                fsp[-2] = argc8;
                proc->pc = proc->pc + (s32)foff;
                break;
            }

            case 9: {
                u16 sub9 = instr >> 6;
                if (sub9 >= 10) {
                    status = 5;
                    break;
                }
                switch (sub9) {
                    case 0:
                        status = 1;
                        break;
                    case 1:
                        status = 2;
                        break;
                    case 2: {
                        s32* rfsp = proc->fsp;
                        s32 ret_pc = rfsp[-1];
                        s32 nargs = rfsp[-2];
                        proc->pc = ret_pc;
                        proc->fsp = rfsp - nargs;
                        if (ret_pc == 0) status = 3;
                        break;
                    }
                    case 3: {
                        func_001da3f8(proc, &L.tos);
                        break;
                    }
                    case 4:
                        status = 5;
                        break;
                    case 5: {  // DUP
                        func_001da3f8(proc, &L.tos);
                        func_001da3d8(proc, (u32)&L.tos);
                        func_001da3d8(proc, (u32)&L.tos);
                        break;
                    }
                    case 6: {  // SIN
                        func_001da3f8(proc, &L.tos);
                        {
                            float k = DAT_0036e690;
                            float k2 = DAT_0036e694;
                            float v = L.tos.f;
                            float r = func_002f8b00(v + k, k2) - k;
                            L.tos.f = func_002f8960(r);
                            func_001da3d8(proc, (u32)&L.tos);
                        }
                        break;
                    }
                    case 7: {  // COS
                        func_001da3f8(proc, &L.tos);
                        {
                            float k = DAT_0036e690;
                            float k2 = DAT_0036e694;
                            float v = L.tos.f;
                            float r = func_002f8b00(v + k, k2) - k;
                            L.tos.f = func_002f87c0(r);
                            func_001da3d8(proc, (u32)&L.tos);
                        }
                        break;
                    }
                    case 8: {
                        func_001da3f8(proc, &L.tos);
                        {
                            float k = DAT_0036e690;
                            float k3 = DAT_0036e698;
                            float k2 = DAT_0036e694;
                            float v = L.tos.f;
                            float scaled = v * k / k3;
                            float r = func_002f8b00(scaled + k, k2) - k;
                            L.tos.f = r;
                            func_001da3d8(proc, (u32)&L.tos);
                        }
                        break;
                    }
                    case 9: {
                        func_001da3f8(proc, &L.tos);
                        {
                            float k = DAT_0036e690;
                            float k3 = DAT_0036e698;
                            float v = L.tos.f;
                            L.tos.f = v * k3 / k;
                            func_001da3d8(proc, (u32)&L.tos);
                        }
                        break;
                    }
                    default:
                        status = 5;
                        break;
                }
                break;
            }

            case 10: {
                int trap_idx = instr >> 6;
                int tpc = proc->pc;
                u8* tcode = proc->code;
                u16 entry_w = *(u16*)(tcode + tpc * 2 + 0x10);
                proc->pc = tpc + 1;

                BD_TRAP* trap = traps[trap_idx];
                BD_TRAP_ENTRY* entry = trap + entry_w;
                BD_VALUE* argbase = L.args;

                int argc = (int)entry->argc - 1;
                if (argc >= 0) {
                    BD_VALUE* dst = argbase + argc;
                    do {
                        func_001da3f8(proc, dst);
                        dst--;
                        argc--;
                    } while (argc >= 0);
                }

                entry->func(argbase);

                if (*(u32*)&entry->argc & 0x40000000u) {
                    func_001da3d8(proc, (u32)argbase);
                }
                break;
            }

            case 11: {
                int cpc2 = proc->pc;
                u8* ccode2 = proc->code;
                s32 argc11 = instr >> 6;
                u8* ip = ccode2 + cpc2 * 2 + 0x10;
                __builtin_memcpy(&L.tmp_offset, ip, 4);
                s32* fsp2 = proc->fsp + argc11;
                proc->fsp = fsp2;
                proc->pc = cpc2 + 2;
                fsp2[-1] = proc->pc;
                fsp2[-2] = argc11;
                proc->pc = proc->pc + L.tmp_offset;
                break;
            }

        }  // switch (op)

    loop_end:
        if (callback) callback(proc, status, userdata);
    } while (status == 0);

    return status;
}
