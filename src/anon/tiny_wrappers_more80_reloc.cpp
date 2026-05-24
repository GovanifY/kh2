#include "../common/types.h"

u32 func_00102508(u32, u32, u32, u32);
u32 func_00102788(u32, u32, u32, u32);
u32 func_00105110(u32, u32, u32, u32);
u32 func_00106420(u32, u32, u32, u32);
u32 func_0010b468(u32, u32, u32, u32);
u32 func_0010b568(u32, u32, u32, u32);
u32 func_00133598(u32, u32, u32, u32);
u32 func_00133630(u32, u32, u32, u32);
u32 func_001336d8(u32, u32, u32, u32);
u32 func_001336e8(u32, u32, u32, u32);
u32 func_00133718(u32, u32, u32, u32);
u32 func_00133720(u32, u32, u32, u32);
u32 func_00133a18(u32, u32, u32, u32);
u32 func_00133ac8(u32, u32, u32, u32);
u32 func_00133ae8(u32, u32, u32, u32);
u32 func_00133b78(u32, u32, u32, u32);
u32 func_00133b88(u32, u32, u32, u32);
u32 func_00133bb8(u32, u32, u32, u32);
u32 func_001342c8(u32, u32, u32, u32);
u32 func_0013dbe0(u32, u32, u32, u32);
u32 func_0013dc38(u32, u32, u32, u32);
u32 func_0013dc58(u32, u32, u32, u32);
u32 func_0013dcb0(u32, u32, u32, u32);
u32 func_0013dd18(u32, u32, u32, u32);
u32 func_00140b68(u32, u32, u32, u32);
u32 func_00142208(u32, u32, u32, u32);
u32 func_00142278(u32, u32, u32, u32);
u32 func_001423c0(u32, u32, u32, u32);
u32 func_00142900(u32, u32, u32, u32);
u32 func_00146e70(u32, u32, u32, u32);
u32 func_00146f28(u32, u32, u32, u32);
u32 func_00149370(u32, u32, u32, u32);
u32 func_001493e8(u32, u32, u32, u32);
u32 func_0014aaa8(u32, u32, u32, u32);
u32 func_0014b248(u32, u32, u32, u32);
u32 func_00170518(u32, u32, u32, u32);
u32 func_00189028(u32, u32, u32, u32);
u32 func_001bb4f0(u32, u32, u32, u32);
u32 func_001cd660(u32, u32, u32, u32);
u32 func_001ce2a0(u32, u32, u32, u32);
u32 func_001d68e0(u32, u32, u32, u32);
u32 func_001d68f8(u32, u32, u32, u32);
u32 func_001d9688(u32, u32, u32, u32);
u32 func_001d9a18(u32, u32, u32, u32);
u32 func_001e0400(u32, u32, u32, u32);
u32 func_001e0448(u32, u32, u32, u32);
u32 func_0023f8a8(u32, u32, u32, u32);
u32 func_00290668(u32, u32, u32, u32);
u32 func_002b89e4(u32, u32, u32, u32);
u32 func_002bcd60(u32, u32, u32, u32);
u32 func_002f3d08(u32, u32, u32, u32);
u32 func_002fd310(u32, u32, u32, u32);
u32 func_002fde18(u32, u32, u32, u32);
u32 func_002feb28(u32, u32, u32, u32);
u32 func_002fee78(u32, u32, u32, u32);
u32 func_002ff970(u32, u32, u32, u32);
u32 func_00303728(u32, u32, u32, u32);
u32 func_00320828(u32, u32, u32, u32);

extern u8 D_0032ba38;
extern u8 D_0032bae0;
extern u8 D_0032e020;
extern u8 D_00330000;
extern u8 D_0033cc18;
extern u8 D_0033cc50;
extern u8 D_00340000;
extern u8 D_00340f30;
extern u8 D_00345cf8;
extern u8 D_00347940;
extern u8 D_00347b88;
extern u8 D_00347c00;
extern u8 D_00347c88;
extern u8 D_00348638;
extern u8 D_00348698;
extern u8 D_00348710;
extern u8 D_00348d58;
extern u8 D_00348d68;
extern u8 D_00349270;
extern u8 D_003494b0;
extern u8 D_00349a00;
extern u8 D_00350000;
extern u8 D_00352a20;
extern u8 D_00352b60;
extern u8 D_0035ead8;
extern u8 D_0035eae8;
extern u8 D_0035eb40;
extern u8 D_0035ebd8;
extern u8 D_00360000;
extern u8 D_00361da8;
extern u8 D_00362d20;
extern u8 D_00363410;
extern u8 D_003637e0;
extern u8 D_00367878;
extern u8 D_00370000;
extern u8 D_003740c8;
extern u8 D_00375958;
extern u8 D_0039ea50;
extern u8 D_003a8ed0;
extern u8 D_003a9040;
extern u8 D_00457580;
extern u8 D_01c5f530;
extern u8 D_01c60d10;
extern u8 D_01d48dc0;
extern u8 D_01d49350;
extern u8 D_01d50000;
extern u8 D_01d5baa0;
extern u8 D_01d60000;
extern u8 D_01d9e900;
extern u8 D_01da0000;
extern u8 D_01e2a410;

u32 func_00102c18(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102788(((u32)(*(u32*)((u32)((u32)&D_00330000) - 18068u))), a0, a1, a2);
}

u32 func_00102f08(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102788(((u32)(*(u32*)((u32)((u32)&D_00330000) - 18012u))), a0, a1, a2);
}

u32 func_001031b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102508((u32)&D_0039ea50, 0x00008000u, a2, a3);
}

u32 func_00103b48(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102788(((u32)(*(u32*)((u32)((u32)&D_00330000) - 17940u))), a0, a1, a2);
}

u32 func_00103e78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002fde18((u32)&D_0032ba38, 0x00000000u, 0x0000000cu, a3);
}

u32 func_00104588(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102788(((u32)(*(u32*)((u32)((u32)&D_00330000) - 17772u))), a0, a1, a2);
}

u32 func_00105d78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102788(((u32)(*(u32*)((u32)((u32)&D_00340000) - 13436u))), a0, a1, a2);
}

u32 func_0010a5f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001342c8((u32)&D_00340f30, 0x0000000au, 0x13000000u, a3);
}

u32 func_0010ab80(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001342c8((u32)&D_003a8ed0, 0x00000017u, 0x13000000u, a3);
}

u32 func_00111000(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0010b568((u32)&D_003a9040, a0, a2, a3);
}

u32 func_00111020(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0010b468((u32)&D_003a9040, a0, a2, a3);
}

u32 func_00113688(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00345cf8);
    return func_00105110(a0, a1, a2, a3);
}

u32 func_00133cf0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133598((u32)&D_00347c88, a0, a1, a3);
}

u32 func_00133d18(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133630((u32)&D_00347c88, a1, a2, a3);
}

u32 func_00133f20(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001336d8((u32)&D_00347c88, a1, a2, a3);
}

u32 func_00133f40(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001336e8((u32)&D_00347c88, a1, a2, a3);
}

u32 func_00133f60(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133720((u32)&D_00347c88, a1, a2, a3);
}

u32 func_00134258(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133718((u32)&D_00347c88, a1, a2, a3);
}

u32 func_001342c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133b88((u32)&D_00347c88, a0, a1, a2);
}

u32 func_00134320(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133bb8((u32)&D_00347c88, a0, 0x00000000u, 0x00000000u);
}

u32 func_00134408(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133a18((u32)&D_00347c88, a1, a2, a3);
}

u32 func_00134428(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133ac8((u32)&D_00347c88, a0, a1, a3);
}

u32 func_00134450(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133ae8((u32)&D_00347c88, ((u32)(a0) & 0xffu), a2, a3);
}

u32 func_00134470(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133b78((u32)&D_00347c88, a1, a2, a3);
}

u32 func_00134490(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00133bb8((u32)&D_00347c88, 0x00000000u, 0x11000000u, 0x13000000u);
}

u32 func_0013dd78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0013dcb0((u32)&D_00348638, a0, a1, a3);
}

u32 func_0013dda0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0013dd18((u32)&D_00348638, a0, a2, a3);
}

u32 func_0013ddc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0013dc38((u32)&D_00348638, a0, a1, a3);
}

u32 func_0013dde8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0013dc58((u32)&D_00348638, a0, a2, a3);
}

u32 func_00140cc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00140b68((u32)&D_00348710, 0x00000000u, a2, a3);
}

u32 func_00143398(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00146f28(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30720u))), a0, 0x00000001u, a3);
}

u32 func_001433c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00146e70(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30720u))), a0, a1, a3);
}

u32 func_001434d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00142900(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30716u))), 0x00000000u, a0, a3);
}

u32 func_00143ea8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00142208(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30716u))), ((u32)(a0) & 0xffffu), a2, a3);
}

u32 func_00143ec8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00142278(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30716u))), ((u32)(a0) & 0xffffu), a2, a3);
}

u32 func_00143f50(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001423c0(((u32)(*(u32*)((u32)((u32)&D_00350000) - 30716u))), ((u32)(a0) & 0xffffu), a1, a3);
}

u32 func_00149350(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00149370((u32)&D_0032bae0, a1, a2, a3);
}

u32 func_00149be8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001493e8((u32)&D_00348d68, a0, a2, a3);
}

u32 func_0014a768(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0014b248((u32)&D_00349270, ((u32)(a0) & 0xffu), a2, a3);
}

u32 func_0014ac48(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0014aaa8((u32)&D_003494b0, a1, a2, a3);
}

u32 func_0014ac90(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0014aaa8((u32)&D_00349a00, a1, a2, a3);
}

u32 func_0014e118(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002fde18((u32)&D_00457580, 0x00000000u, 0x0009c000u, a3);
}

u32 func_0016e0c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00189028((u32)&D_0032e020, ((u32)(*(u32*)((u32)(a0) + 0u))), ((u32)(*(u32*)((u32)(a0) + 4u))), ((u32)(*(u32*)((u32)(a0) + 8u))));
}

u32 func_00179bc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d68e0((u32)&D_01c5f530, a1, a2, a3);
}

u32 func_00179be8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d68f8((u32)&D_01c5f530, a1, a2, a3);
}

u32 func_001913b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001cd660((u32)&D_01c60d10, a1, a2, a3);
}

u32 func_001a3a50(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00170518(((u32)(*(u32*)((u32)((u32)&D_00350000) + 1864u))), 0x000003e8u, 0x00000000u, a3);
}

u32 func_001ba138(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002fd310((u32)&D_01d48dc0, 0x0000001cu, a2, a3);
}

u32 func_001bb740(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001bb4f0(((u32)(*(u32*)((u32)((u32)&D_01d50000) - 27872u))), 0x00000010u, a0, a3);
}

u32 func_001c0248(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00320828((u32)&D_01d49350, a0, a2, a3);
}

u32 func_001ce2d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ce2a0(((u32)(*(u32*)((u32)((u32)&D_01d60000) - 17968u))), a0, 0x00000001u, a3);
}

u32 func_001ce300(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ce2a0(((u32)(*(u32*)((u32)((u32)&D_01d60000) - 17964u))), ((u32)(a0) - 1u), 0x00000000u, a3);
}

u32 func_001ce328(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ce2a0(((u32)(*(u32*)((u32)((u32)&D_01d60000) - 17960u))), a0, 0x00000001u, a3);
}

u32 func_001ce350(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ce2a0(((u32)(*(u32*)((u32)((u32)&D_01d60000) - 17956u))), a0, 0x00000000u, a3);
}

u32 func_001d96c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d9688(((u32)(*(u32*)((u32)((u32)&D_00370000) - 6592u))), a0, a1, a3);
}

u32 func_001d9ad8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d9a18((u32)&D_01d5baa0, a0, a2, a3);
}

u32 func_001e0428(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001e0400((u32)&D_00352b60, a1, a2, a3);
}

u32 func_001e0670(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001e0448((u32)&D_00352b60, a1, a2, a3);
}

u32 func_001eb2a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002f3d08(((u32)(((u32)(*(u32*)((u32)((u32)&D_01da0000) - 6424u)))) + 80u), (u32)&D_01d9e900, ((u32)(((u32)(*(u32*)((u32)((u32)&D_01da0000) - 6424u)))) + 16u), a3);
}

u32 func_001f0400(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002f3d08(((u32)(((u32)(*(u32*)((u32)((u32)&D_01da0000) - 6424u)))) + 80u), (u32)&D_01d9e900, ((u32)(((u32)(*(u32*)((u32)((u32)&D_01da0000) - 6424u)))) + 16u), a3);
}

u32 func_0023f7e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_0035ebd8);
    return func_0023f8a8(a0, a1, a2, a3);
}

u32 func_0023f800(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_0035ebd8);
    return func_0023f8a8(a0, a1, a2, a3);
}


u32 func_0027db28(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00290668(((u32)(*(u32*)((u32)((u32)&D_00360000) - 3528u))), ((u32)(*(u32*)((u32)((u32)&D_00360000) - 3520u))), ((u32)(*(u32*)((u32)((u32)&D_00360000) - 3524u))), 0x00000000u);
}

u32 func_00280420(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002fee78(a0, (u32)&D_003740c8, ((u32)(*(u32*)((u32)((u32)&D_00340000) - 13580u))), ((u32)(*(s8*)((u32)(((u32)(((u32)(*(u32*)((u32)((u32)&D_00360000) - 3488u)))) + (u32)(a1))) + 8u))));
}

u32 func_002ba810(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002bcd60((u32)&D_01e2a410, a0, a2, a3);
}

u32 func_002bd760(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002b89e4(((u32)(*(u32*)((u32)((u32)&D_00360000) + 6124u))), 0x00000000u, a0, a3);
}

u32 func_002ceae8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002fee78(a1, (u32)&D_00375958, a2, a3);
}

u32 func_002f17e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00170518(((u32)(*(u32*)((u32)((u32)&D_00360000) + 15392u))), 0x000003b6u, 0x00000000u, a3);
}

u32 func_002fed30(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002feb28(((u32)(*(u32*)((u32)((u32)&D_00360000) + 23624u))), a0, a1, a3);
}

u32 func_002ffbb0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002ff970(((u32)(*(u32*)((u32)((u32)&D_00360000) + 23624u))), a0, a1, a2);
}

u32 func_003037c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00303728(((u32)(*(u32*)((u32)((u32)&D_00360000) + 23624u))), a0, a1, a3);
}

u32 func_00321a70(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00352a20);
    return func_00105110(a0, a1, a2, a3);
}

u32 func_00321aa0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00352a20);
    return func_00105110(a0, a1, a2, a3);
}

u32 func_00321ad0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00352a20);
    return func_00105110(a0, a1, a2, a3);
}

u32 func_00321b00(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00352a20);
    return func_00105110(a0, a1, a2, a3);
}

u32 func_003251f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00361da8);
    return func_00105110(a0, a1, a2, a3);
}
