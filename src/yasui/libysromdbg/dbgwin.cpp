#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class ...;
class ELEM;
struct TASK;
class WIDGET;

class DBGWIN {
public:
 void Pause(void);
 void PauseOff(void);
 bool _IsPause(void);
 void StatusPrintf(char* a0, ...);
 void ExecTask(TASK* a0);
 void TopMenuFinalize(WIDGET* a0);
 void TopMenuMake(void);
 void AddMenuElem(ELEM* a0, s32 a1, ELEM* a2);
 void AddSubMenu(s32 a0, ELEM* a1);
 void SubMenuCallback(s32 a0);
 void Init(void);
 void Show(WIDGET* a0);
 void AddObjMenu(ELEM* a0);
 void GetMenuObj(void);
 void TopMenuPopup(s32 a0, s32 a1);
 u64 OpenWindow(char* a0, s32 a1, s32 a2, u32 a3);
 void SendFont(void);
 u64 IsActiveSubMenu(s32 a0);
 bool IsPause(void);
};
