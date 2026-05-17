#pragma once

#include "../common/types.h"
#include "../common/task.hpp"

class ALLOCATOR;
class FuncDef45;
class FuncDef46;
class FuncDef47;
class PAD;

namespace Tz {

class MenuBase {
public:
    static void ResetPad();
    static void SavePadInit(ALLOCATOR*);
    static void Init(s32, s32, bool);
    static void SavePadExit();
    static void Exit();
    static void Reset();
    static u32 IsExit();
    static u32 IsChgMode();
    static u32 isSavePad();
    static void SetExit();
    static void SetMode(s32, s32);
    static u32 NextMode2Mode();
    static void SetSignal(s32);
    static void SetModeMax(s32, s32);
    static s32 GetMode();
    static void SetNextMode(s32);
    static s32 GetNextMode();
    static void IncSMode(s32);
    static void SetSMode(s32);
    static s32 GetSMode();
    static void SetPhase(s32);
    static s32 GetPhase();
    static void SaveMode();
    static void* GetMenuObj();
    static u32 PadSE(s32, bool, bool, FuncDef45*, bool);
    static void SetLoadImage(bool);
    static u32 GetLoadImage();
    static void SavePad(PAD*);
    static s32 GetPad();
    static bool isPressAnyKey();
    static u32 NextModeToMode(...);
};

class MenuBasic {
public:
    static void MenuThread(TASK*);
    static void Setup();
    static void PauseThread(TASK*);
    static void ExitCallback();
    static void Init();
    static void Exit();
    static void SetStartMenu(s32);
    static void SetNextMenu(s32, s32);
    static void StartFade(FuncDef46*);
    static void EndFade(void (*)());
    static u32 isExistFade();
    static u32 CheckFade();
    static s32 GetMenuId();
    static u32 GetGraRes(...);
    static u32 GetMesRes(...);
    static void SetGraRes(...);
    static void SetMesRes(...);
    static s32 GetMenuNameId(u32);
    static u32 IsFadeRunning(...) asm("_ZN2Tz5Pause7isPauseEv");
    static u32 GetFadeState(...) asm("_ZN2Tz5Pause11isExistFadeEv");
    static u32 CheckFadeDone(...) asm("_ZN2Tz5Pause10isLoopFadeEv");
    static void EndFadeImpl(u32) asm("_ZN2Tz5Pause7EndFadeEPFvvE");
};

class CmSLBase {
public:
    static void FadeOutWarningWin();
    static u32 isLoopWarningWin();
    static u32 isLoopList();
    static void LoopList();
    static void FadeOutList();
    static void isExistList();
    static void LeaveListItem();
    static void SetLeadData();
    static void ResetListItem();
    static u32 GetCurrentListItem();
    static u32 LeaveListItemImpl();
    static u32 GetLeadMesId(u32);
};

}  // namespace Tz

