#include "ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"

namespace Tz {
extern "C" u32 func_00139d78(...);

s64 CmComm::GetIconMsgSize() { return 2; }
s32 PartyInfo::GetPartyMax() { return reinterpret_cast<PartyInfoLayout*>(this)->partyMax; }
s32 PartyInfo::GetParty(s32 index) {
    return (s32)(*(s16*)((char*)this + ((u32)index * 20) + 4));
}
u32 PartyInfo::GetName(s32 index) {
    return *(u32*)((char*)this + ((u32)index * 20) + 12);
}
u32 PartyInfo::GetSheet(s32 index) {
    return *(u32*)((char*)this + ((u32)index * 20) + 20);
}
extern "C" u32 func_001a8bd0(...);
extern "C" u32 func_001a8bf8(...);
extern u32 D_00374190 asm("D_00374190");
u32 PartyInfo::GetEntryId(s32 index) {
    u32 i = 0;
    while (true) {
        u32 t = func_001a8bd0(-1);
        u32 l = func_001a8bf8(t, i);
        u32 r = func_001a8bf8(*(u32*)((u32)this + 84), (u32)index);
        if (l == r) {
            break;
        }
        i += 1;
        if ((s32)i >= 4) {
            break;
        }
    }
    return ((u32*)&D_00374190)[i];
}
extern "C" u32 func_00281180(...);
extern "C" u32 func_00281198(...);
extern "C" u32 func_00281128(...);
extern "C" u32 func_001a9758(...);
u32 PartyInfo::isLoadObj(s32 index) {
    u32 ok = func_00281180((u32)this, (u32)index);
    u32 out = 0;
    if (ok != 0) {
        u32 t = func_00281198((u32)this, (u32)index);
        u32 obj = GetEntryId((s32)t);
        u32 tmp = func_00281128((u32)this, (u32)index);
        (void)tmp;
        out = func_001a9758(obj, 0);
    }
    return out;
}
extern "C" u32 func_001058e8(...);
u32 PartyInfo::GetNowForm() {
    u32 r2 = func_001058e8();
    r2 = (u32)(*(u8*)((u32)r2 + (s32)(13604)));
    return r2;
}
u32 PartyInfo::isSora(s32 index) {
    u32 t6 = *(u32*)((char*)this + ((u32)index * 20) + 16);
    u32 v0 = 0u;
    if (t6 != 0u) {
        v0 = (u32)(*(u16*)(t6 + 76u) == 1u);
    }
    return v0;
}
extern "C" u32 func_00281340(...);
u32 PartyInfo::isDoubleWeaponForm(s32 index) {
    u32 v0 = 0u;
    if ((u32)index == 1u || (u32)index == 4u || (u32)index == 5u) {
        v0 = 1u;
    }
    return v0;
}
u32 PartyInfo::GetAllHaveForm() {
    u32 mask = 0;
    for (s32 i = 0; i < 7; i++) {
        if (i != 0) {
            if (func_00281340((u32)i) != 0) {
                mask |= (1u << (u32)i);
            }
        }
    }
    return mask;
}
u32 PartyInfo::GetAllDoubleWeaponForm() {
    u32 mask = 0;
    for (s32 i = 0; i < 7; i++) {
        if (isDoubleWeaponForm(i) != 0) {
            mask |= (1u << (u32)i);
        }
    }
    return mask;
}
s32 ItemInfo::GetInfoMax() { return reinterpret_cast<ItemInfoLayout*>(this)->infoMax; }
void* ItemInfo::GetInfo() { return reinterpret_cast<void*>((char*)this + 4); }
void* ItemInfo::GetMsgTbl() { return reinterpret_cast<void*>((char*)this + 1540); }
void ItemInfo::SetPartyInfo(PartyInfo* v) {
    reinterpret_cast<ItemInfoLayout*>(this)->partyInfo = v;
}
s64 ItemInfo::GetItemNoneMsgId() { return 0x8449; }
void MultiSeq::setExMode(s32 v) { reinterpret_cast<MultiSeqLayout*>(this)->exMode = v; }
u32 HelpGra::isExist() {
    u32 (*fp_call0_00139d78)() = (u32(*)())func_00139d78;
    return fp_call0_00139d78();
}
}  // namespace Tz
