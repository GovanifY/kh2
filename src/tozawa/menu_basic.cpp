#include "types.h"


namespace Tz {

} // namespace Tz

class FuncDef46;
class FuncDef47;
struct TASK;

class MenuBasic {
public:
 void CheckFade(void);
 void MenuThread(TASK* a0);
 void Setup(void);
 void PauseThread(TASK* a0);
 void ExitCallback(void);
 void Init(void);
 void Exit(void);
 void SetStartMenu(s32 a0);
 void SetNextMenu(s32 a0, s32 a1);
 void StartFade(FuncDef46* a0);
 void EndFade(FuncDef47* a0);
 u64 isExistFade(void);
 u64 GetMenuId(void);
};
