#include "jm_album.hpp"

namespace Tz {

extern u32 D_0035f598 asm("D_0035f598");
extern u32 D_0035f520 asm("D_0035f520");
extern s8 D_0035f5a1 asm("D_0035f5a1");
extern u8 D_0035f5a3 asm("D_0035f5a3");
u32 LoadDataIsFlushing();
void LayFileBuildData(void*, u32);
void LayFileSetImdData(u32, u32);
void LayFileReset();
void LoadDataFlush();

void JmAlbum::RequestGraLoad(s32 a0) {
    u8 buf[32];
    s32 idx = (s8)a0;
    u32 off = (u32)idx;
    off <<= 1;
    off += D_0035f598;
    D_0035f5a1 = (s8)a0;
    u32 s0 = (u32)GetAlbumData(*(s16*)(off + 4));
    if (LoadDataIsFlushing() != 0) {
        D_0035f5a3 = 0;
        return;
    }
    u32 v = GetImageName(*(s8*)s0);
    LayFileBuildData(buf, v);
    LayFileSetImdData((u32)buf, s0 + 1);
    LayFileReset();
    RequestLoad(3, buf, 0);
    LoadDataFlush();
    D_0035f5a3 = 1;
}

u32 JmAlbum::GetImageName(u32 index) {
    return *(u32*)((u32)&D_0035f520 + (index << 2));
}

}  // namespace Tz
