#include "jm_info.hpp"
#include "file_address_layout.hpp"
#include "../yasui/libys/progress.hpp"

namespace YS {
}  // namespace YS

namespace Tz {

u32 JmInfo::GetData(s32 index) {
    u32 r5 = (u32)index;
    u32 r15 = (u32)(0x0036u << 16);
    u32 r4 = *(volatile u32*)((u32)r15 + (s32)(-2700));
    return GetDataImpl(r4, r5);
}

u32 JmInfo::GetDefeatCnt(JmCharaDataInfo const* info) {
    u32 r15 = (u32)(*(u16*)((u32)info + (s32)(16)));
    r15 = (u32)(r15 & 0x0800u);
    u32 r2 = 0u;
    if (r15 != 0u) {
        u32 r4 = (u32)(*(u16*)((u32)info + (s32)(12)));
        r2 = GetCharaData(r4);
        u32 r16 = (u32)(*(u16*)((u32)r2 + (s32)(76)));
        r2 = JiminyGetBase();
        r4 = (u32)((s32)r2 + (9456));
        r2 = FindDefeatCount(r4, r16);
    }
    return r2;
}

u32 JmInfo::isWorldOpen(JmWorldDataInfo const* info) {
    u32 r15 = (u32)(s32)(*(s8*)((u32)info + (s32)(0)));
    r15 = ((s32)r15 < (16));
    u32 r2 = 1u;
    if (r15 != 0u) {
        u32 r4 = (u32)(*(u16*)((u32)info + (s32)(8)));
        r2 = YS::PROGRESS::CheckFlag((s32)r4);
    }
    return r2;
}

u32 JmInfo::isWorldChgName(JmWorldDataInfo const* info) {
    u32 r2 = 0u;
    u32 r15 = (u32)(*(u16*)((u32)info + (s32)(14)));
    u32 r4 = r15;
    if (r15 != 0u) {
        r2 = YS::PROGRESS::CheckFlag((s32)r4);
    }
    return r2;
}

u32 JmInfo::isEnableStory(JmStoryDataInfo const* info) {
    u32 r4 = (u32)(*(u16*)((u32)info + (s32)(10)));
    u32 r2 = YS::PROGRESS::CheckFlag((s32)r4);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

u32 JmInfo::isEnableAlbum(JmAlbumDataInfo const* info) {
    u32 r4 = (u32)(*(u16*)((u32)info + (s32)(6)));
    u32 r2 = YS::PROGRESS::CheckFlag((s32)r4);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

u32 JmInfo::isHaveAnsem(JmAnsemDataInfo const* info) {
    u32 r4 = (u32)(*(u16*)((u32)info + (s32)(0)));
    u32 r2 = HasAnsemEntry(r4);
    r2 = ((u32)0u < (u32)r2);
    return r2;
}

u32 JmInfo::isEnableLimit(JmLimitDataInfo const* info) {
    u32 r4 = (u32)(*(u16*)((u32)info + (s32)(0)));
    u32 r2 = GetLimitEntry(r4);
    r4 = r2;
    r2 = IsLimitEnabled(r4);
    r2 = ((s32)0u < (s32)r2);
    return r2;
}

extern u32 D_0035f570 asm("D_0035f570");
extern u32 D_0035f574 asm("D_0035f574");
extern u32 D_0035f578 asm("D_0035f578");
void LoadDataFree(...);

u32 JmInfo::IsLoaded(u32 data) {
    return reinterpret_cast<const FileAddressLayout*>(data)->fileAddress;
}

void JmInfo::Exit() {
    if (D_0035f574 != 0) {
        if (IsLoaded(D_0035f574) != 0) {
            Unload(D_0035f574);
        }
    }
    if (D_0035f574 != 0) {
        u32 p = D_0035f574;
        ((void (*)(u32))(*(u32*)(*(u32*)p + 4)))(p);
        D_0035f574 = 0;
    }
    if (D_0035f578 != 0) {
        LoadDataFree(D_0035f578);
        D_0035f578 = 0;
    }
    D_0035f570 = 0;
}

u32 JmInfo::isInit() { return (D_0035f570 != 0); }

}  // namespace Tz
