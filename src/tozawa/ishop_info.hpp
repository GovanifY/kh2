#ifndef KH2_SRC_TOZAWA_ISHOP_INFO_HPP
#define KH2_SRC_TOZAWA_ISHOP_INFO_HPP

#include "../common/types.h"

namespace Tz {

class ShopTbl;

class IShopInfo {
public:
    u64 ChkData(void* a0);
    u64 GetItemStat(s32 a0);
    void AddItemData(ShopTbl* a0, ushort* a1, s32 a2, u16 a3);
    void GetSpecialty(s32 a0, u16 a1, ShopTbl* a2);
    void GetShopTbl(s32 a0, ShopTbl* a1);
    void SetDataPtr(void* a0);
    s32 GetItem2LogIdx(s32 a0);
};

}  // namespace Tz

#endif
