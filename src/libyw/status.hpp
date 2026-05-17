#ifndef KH2_SRC_LIBYW_STATUS_HPP
#define KH2_SRC_LIBYW_STATUS_HPP

#include "../common/types.h"

class COLOR;
class RECT;

class STATUS {
public:
    STATUS();
    ~STATUS();
    void CheckEnemy();
    void SetLockOutRange(f32 a0);
    void SetLockOnRatio(f32 a0);
    void Init();
    u32 GetMode();
    u64 IsBattleMode();
    void CheckBattleMode();
    void CageOn();
    void CageOff();
    u64 IsPrizeDrain();
    u64 IsPeterpanPrizeDrain();
    void StopStart();
    void StopEnd();
    u64 IsDisableZone();
    void SetPrizeRatio(f32 a0);
    double GetPrizeRatio();
    double GetLockOnRatio();
    double GetLockOutRange();
    u64 IsFreeAbility();
    u64 IsHideNaviMap();
    u64 IsDisableCampMenu();
    void clear();
    STATUS(STATUS* a0, s32 a1, s32 a2, s32 a3, u32 a4);
    ~STATUS();
    void vprintf(char* a0, char* a1);
    void idle_func();
    void draw_func(RECT* a0, COLOR* a1);
};

#endif
