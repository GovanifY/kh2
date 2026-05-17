#pragma once

#include "../../common/types.h"

class CODE;
class COMMAND_ELEM;
class MISSION;
class PARTYATTACK;
class TABLE;
struct TASK;

namespace YS {

    class MISSION {
    public:
     void prepare(void);
     u64 IsExec(void);
     s32 ShowInformation(s32 a0);
     u32 GetCurrent(void);
     u64 IsMiniGame(void);
     u32 activate(void);
     void end(void);
     void End(void);
     void EndSignal(s32 a0, s32 a1);
     u64 exec(void);
     void PostEnd(void);
     void complete(s32 a0, s32 a1);
     u64 CodeParser(CODE* a0, void* a1);
     void Exec(TASK* a0);
     MISSION(MISSION* a0, s32 a1, char* a2);
     void Init(void);
     void Start(s32 a0, char* a1);
     void Prepare(void);
     void ReadRequest(void);
     void Activate(void);
     u64 IsActive(void);
     u64 IsShowWeapon(void);
     u64 IsMickey(void);
     u64 IsNoExp(void);
     u64 IsFailedContinue(void);
     u64 IsDisableMagic(void);
     u64 IsContinueSave(void);
     u64 IsControl(void);
     u64 IsDisableKH1Form(void);
     u64 IsEnablePlace(void);
     void Complete(s32 a0);
     void DeadBoss(s32 a0);
     void Failed(void);
     void Exit(s32 a0);
     void ResetPauseMode(void);
     void Return(void);
     void Quit(s32 a0);
     u64 ShowHelp(void);
     void ExecCommand(COMMAND_ELEM* a0);
     void ExecPartyAttack(PARTYATTACK* a0);
     u32 GetCurrentId(void);
     u8 GetAntiRate(void);
     void SetPause(u32 a0);
     void ResetPause(u32 a0);
     s32 GetLimitCost(s32 a0);
     double GetDriveAddRatio(void);
     u64 IsFreeSummon(void);
     u64 IsDisableSummon(void);
     void activate_2d(void);
     void init_mission2d(TABLE* a0, MISSION2D* a1);
     void start_timer(TABLE* a0);
     void start_count(TABLE* a0);
     void start_gauge(TABLE* a0);
     void start_watch(TABLE* a0);
     void start_combo(TABLE* a0);
     void SetTimerParam(s32 a0, s32 a1, s32 a2, s32 a3);
     void RestartTimer(s32 a0, s32 a1);
     u64 GetTimer(s32 a0);
     u32 GetTimerSecond(s32 a0);
     void WarningTimer(s32 a0);
     void DisableTimer(s32 a0);
     void SetCountParam(s32 a0, s32 a1, s32 a2, s32 a3);
     void SetCount(s32 a0, s32 a1);
     void AddCountForce(s32 a0, s32 a1);
     void AddCount(s32 a0, s32 a1);
     void ResetCount(s32 a0);
     u32 GetCount(s32 a0);
     bool IsCountWarning(s32 a0);
     void DisableCount(s32 a0);
     void SetCountWarningSe(s32 a0, s32 a1);
     void SetCountFigureNum(s32 a0, s32 a1, s32 a2);
     void WarningCount(s32 a0, bool a1);
     void SetGaugeParam(s32 a0, s32 a1, s32 a2, s32 a3);
     void SetGauge(f32 a0, s32 a1);
     void AddGauge(f32 a0, s32 a1);
     void SetGaugeRatio(f32 a0, s32 a1);
     double GetGaugeRatio(s32 a0);
     double GetGaugeWarningRatio(s32 a0);
     bool IsGaugeWarning(s32 a0);
     void WarningGauge(bool a0, s32 a1);
     void SetWatch(s32 a0, s32 a1);
     void DisableWatch(s32 a0);
     void Activate2d(void);
     void Deactivate2d(void);
     u64 IsActivate2d(void);
     void AddComboCounter(s32 a0, f32 a1, s32 a2);
     void ResetComboCounter(s32 a0);
     u32 GetMaxComboCounter(s32 a0);
     u32 GetComboCounter(s32 a0);
     void SetMaxComboCounter(s32 a0, s32 a1);
     void SetComboCounterParam(s32 a0, s32 a1, s32 a2, s32 a3);
     void WarningComboCounter(s32 a0);
     void SetComboCounterWarningSe(s32 a0, s32 a1);
     void OptionInit(s32 a0);
     void OptionRead(s32 a0);
     void OptionStart(s32 a0);
     void OptionEnd(s32 a0);
    };

}  // namespace YS

