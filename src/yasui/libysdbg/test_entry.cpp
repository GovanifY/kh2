#include "../../common/types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

struct TASK;

class TEST_ENTRY {
public:
 void Init(void);
 void LeaveAllThread(TASK* a0);
 void CaptureCallback(u32 a0);
 void CaptureThread(TASK* a0);
 void NewObj(u32 a0);
 void Exec(void);
 void SelectMenuCallback(s32 a0);
 void ChangePlayer(u32 a0);
 void ChangePlayerThread(TASK* a0);
 void NewObj3(u32 a0);
 void NewObj5(u32 a0);
 void NewObj10(u32 a0);
 void NewObj20(u32 a0);
 void NewObj30(u32 a0);
 void NewObj50(u32 a0);
 void NewActor(u32 a0);
 void NewObjThread(TASK* a0);
 void ReloadThread(TASK* a0);
 void NewFriend(u32 a0);
};
