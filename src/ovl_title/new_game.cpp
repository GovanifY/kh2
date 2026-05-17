#include "../common/types.h"


struct TASK;

class NewGame {
public:
 void isExistWin(void);
 void FadeOutWait(TASK* a0);
 void FadeOutWin(void);
 void UpdateHelpMsg(void);
 void CreateBase(void);
 void SetupConfig(void);
 void CtrlResult(void);
 void SetupResult(void);
 void CtrlConfig(void);
 u64 CtrlMode(TASK* a0);
 void Draw(TASK* a0);
 void Init(void);
 void Exit(void);
 u64 Control(TASK* a0);
 void SetConfig(void);
};

s32 new_game(void);
