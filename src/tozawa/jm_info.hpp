#ifndef KH2_SRC_TOZAWA_JM_INFO_HPP
#define KH2_SRC_TOZAWA_JM_INFO_HPP

#include "../common/types.h"

namespace Tz {

struct JmStoryDataInfo;
struct JmAlbumDataInfo;
struct JmAnsemDataInfo;
struct JmWorldDataInfo;
struct JmCharaDataInfo;
struct JmLimitDataInfo;

u32 JiminyGetBase() asm("_Z10getSaveRamv");

class JmInfo {
public:
    static void Exit();
    static u32 isInit();
    static u32 GetData(s32);
    static u32 GetDefeatCnt(JmCharaDataInfo const*);
    static u32 isWorldOpen(JmWorldDataInfo const*);
    static u32 isWorldChgName(JmWorldDataInfo const*);
    static u32 isEnableStory(JmStoryDataInfo const*);
    static u32 isEnableAlbum(JmAlbumDataInfo const*);
    static u32 isHaveAnsem(JmAnsemDataInfo const*);
    static u32 isEnableLimit(JmLimitDataInfo const*);
    static u32 GetCharaData(u32);
    static u32 FindDefeatCount(u32, u32);
    static u32 GetDataImpl(...);
    static u32 HasAnsemEntry(u32);
    static u32 GetLimitEntry(...);
    static u32 IsLimitEnabled(...);
    static u32 IsLoaded(...);
    static void Unload(...);
};

}  // namespace Tz

#endif
