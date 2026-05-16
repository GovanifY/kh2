#include "types.h"


namespace YS {

} // namespace YS

class FVector;
class OBJENTRY;

class OBJENTRY {
public:
 u32 get_weapon_entry(s32 a0);
 u64 Get(u32 a0);
 u64 IsActor(u32 a0);
 void ReadRequestWeapon(s32 a0, s32 a1, u32 a2, s32 a3, s32 a4);
 u64 IsMenu(u32 a0);
 u64 is_exist_mset(void);
 s32 GetFriendPriority(u32 a0);
 s32 AllocFriendPriority(u32 a0);
 void ReadRequestSub(u32 a0, s32 a1, s32 a2, s32 a3);
 void Load(void);
 void ReadRequestForm(s32 a0);
 u64 ReadRequest(u32 a0, s32 a1, s32 a2);
 u64 Appear(u32 a0, FVector* a1, f32 a2);
 void Each(OBJENTRY* a0);
 u32 GetPriority(s32 a0);
 u32 GetTypeString(s32 a0);
 u32 GetCacheBuffStatus(u32 a0, OBJENTRY* a1);
 void InitArea(void);
};
