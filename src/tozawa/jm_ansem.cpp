#include "types.h"


namespace Tz {

} // namespace Tz

class SpriteMessage;

class JmAnsem {
public:
 s32 GetEnableCnt(void);
 void SetupInfo(void);
 void UpdateTopList(void);
 void UpdateNewMark(void);
 void MovePage(s32 a0);
 void DrawMess(s32 a0, s32 a1, u32 a2, u32 a3, SpriteMessage* a4);
 u64 SelCheck(s32 a0);
 void Exit(void);
 void FadeOutAll(void);
 void LeaveAll(void);
 void GetHaveReport(void);
 void SetupTop(void);
 void CtrlTop(void);
 void CtrlInfo(void);
 u64 isEnableAnsemReport(void);
};
