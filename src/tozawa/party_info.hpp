#pragma once

#include "../common/types.h"

namespace Tz {

class MEMBER;

class PartyInfo {
public:
    u32 GetEntryId(s32 a0);
    void CreateBuffer(MEMBER* a0);
    PartyInfo(PartyInfo* a0, MEMBER* a1);
    ~PartyInfo();
    void Reload(s32 a0);
    void Update(MEMBER* a0);
    s32 GetPartyMax(void);
    u32 GetObjEntry(s32 a0);
    u32 GetName(s32 a0);
    void GetNameId(s32 a0);
    u32 GetSheet(s32 a0);
    s32 GetParty(s32 a0);
    u16 GetPartNum(s32 a0);
    u16 GetMemberId(s32 a0);
    u32 GetDirectEntryId(s32 a0);
    u64 isIllegalWorld(void);
    u64 isHaveForm(s32 a0);
    static u32 isDoubleWeaponForm(s32 a0);
    static u32 GetAllHaveForm(void);
    static u32 GetAllDoubleWeaponForm(void);
    u32 isSora(s32 a0);
    s64 Party2Idx(s32 a0);
    u16 GetFormWeapon(s32 a0);
    void SetFormWeapon(s32 a0, s32 a1);
    u32 isLoadObj(s32 a0);
    u32 GetNowForm(void);
};

}  // namespace Tz

