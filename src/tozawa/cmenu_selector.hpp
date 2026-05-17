#ifndef KH2_SRC_TOZAWA_CMENU_SELECTOR_HPP
#define KH2_SRC_TOZAWA_CMENU_SELECTOR_HPP

#include "types.h"

namespace dk {
class Sprite;
}

struct TASK;

namespace YI {
class SEQUENCE;
}

namespace Tz {

void PauseTaskSetup(...);
void TaskYield(...);
void PauseTaskBegin();
u32 PauseTaskIsDone(...);
void PauseTaskUpdate();

class MenuCursor {
public:
    static u32 GetPri(s32);
    static dk::Sprite* GetSprite(s32);
    static bool isInit();
    static void SetParentSeq(s32, YI::SEQUENCE*);
    static u32 GetInputState(...);
    static void SetFlag(...);
    static void Create(...);
    static void AttachSprite(...);
    static void DeleteAll(...);
    static u32 isAlive(...) asm("_ZN2Tz8LightCur7isExistEv");
};

class Selector {
public:
    static u32 SelExit();
    static void SetupHelpGra();
    static void Control(TASK*);
    static void PauseThread(TASK*);
    static u32 SelExitImpl(...);
    static void GetHelpGraPos(...);
    static void SetHelpGraMsg(...);
    static void CreateHelpGra(...);
    static void SetState(...);
    static u32 GetState(...);
    static u32 HelpGraDone(...);
};

}  // namespace Tz

#endif
