#ifndef KH2_SRC_TOZAWA_ITEM_INFO_HPP
#define KH2_SRC_TOZAWA_ITEM_INFO_HPP

#include "types.h"

namespace Tz {

class PartyInfo;

class ItemInfo {
public:
    static u32 GetEquipMax(s32);
    static u32 GetItemEmptyMsg(s32);
    s32 GetInfoMax();
    void* GetInfo();
    void* GetMsgTbl();
    void SetPartyInfo(PartyInfo* v);
    s64 GetItemNoneMsgId();
};

}  // namespace Tz

#endif
