#include "types.h"


namespace YS {

} // namespace YS

class ITEM_TABLE;

class ITEM {
public:
 void UseSub(ITEM_TABLE* a0, s32 a1, s32 a2, s32 a3);
 u64 CanUseSub(ITEM_TABLE* a0, s32 a1);
 void ReduceBackyard(s32 a0, s32 a1);
 u8 GetNumBackyard(s32 a0);
 u32 GetForm(ITEM_TABLE* a0);
 u64 GetCommand(s32 a0);
 void KnowBattleItem(s32 a0);
 u64 IsAll(s32 a0);
 u64 Use(s32 a0, s32 a1, s32 a2, s32 a3);
 s32 WhereGet(s32 a0, s32 a1, s32 a2);
 u64 CanGet(s32 a0, s32 a1, s32 a2);
 void GetBackyard(s32 a0, s32 a1);
 u64 Get(s32 a0, s32 a1, bool a2);
 u64 Reduce(s32 a0, s32 a1);
 s32 GetNum(s32 a0, s32 a1);
 u16 FormToItem(s32 a0);
 u16 MagicToItem(s32 a0);
 void Recharge(void);
 s32 MakeMessage(char* a0, s32 a1, s32 a2);
 void GetCommandElem(s32 a0);
 u64 CanUse(s32 a0, s32 a1);
};
