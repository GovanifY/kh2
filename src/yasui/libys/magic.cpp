#include "types.h"


namespace YS {

} // namespace YS

class MAGIC;
struct TASK;

class MAGIC {
public:
 ~MAGIC();
 void ExecTask(TASK* a0);
 void ClearAll(void);
 void Finalizer(TASK* a0);
 void shot(void);
 void set_cost(f32 a0);
 void SysInit(void* a0);
 void Init(void);
 void Read(void);
 u16 GetCommand(s32 a0);
 void MpDriveEnable(s32 a0);
 u8 GetMpDriveStatus(s32 a0);
 void MpDriveDisable(s32 a0);
 bool CanAddCost(f32 a0);
 void Delete(MAGIC* a0);
 u64 IsFriendCasting(void);
 void Reset(void);
};
