#include "types.h"


namespace Tz {

} // namespace Tz

class ALLOCATOR;
class FuncDef45;
class PAD;

class MenuBase {
public:
 void ResetPad(void);
 void SavePadInit(ALLOCATOR* a0);
 void Init(s32 a0, s32 a1, bool a2);
 void SavePadExit(void);
 void Exit(void);
 void Reset(void);
 void SetSignal(s32 a0);
 void SetExit(void);
 u64 IsExit(void);
 void SetModeMax(s32 a0, s32 a1);
 u64 IsChgMode(void);
 u32 GetMode(void);
 void SetMode(s32 a0, s32 a1);
 void SetNextMode(s32 a0);
 u32 GetNextMode(void);
 void NextMode2Mode(void);
 void IncSMode(s32 a0);
 void SetSMode(s32 a0);
 u32 GetSMode(void);
 void SetPhase(s32 a0);
 u32 GetPhase(void);
 void SaveMode(void);
 u32 GetMenuObj(void);
 u64 PadSE(s32 a0, bool a1, bool a2, FuncDef45* a3, bool a4);
 void SetLoadImage(bool a0);
 u64 GetLoadImage(void);
 void SavePad(PAD* a0);
 s32 GetPad(void);
 u64 isSavePad(void);
 bool isPressAnyKey(void);
};
