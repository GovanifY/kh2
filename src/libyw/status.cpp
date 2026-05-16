#include "types.h"


class COLOR;
class RECT;
class STATUS;

class STATUS {
public:
 STATUS();
 ~STATUS();
 void CheckEnemy(void);
 void SetLockOutRange(f32 a0);
 void SetLockOnRatio(f32 a0);
 void Init(void);
 u32 GetMode(void);
 u64 IsBattleMode(void);
 void CheckBattleMode(void);
 void CageOn(void);
 void CageOff(void);
 u64 IsPrizeDrain(void);
 u64 IsPeterpanPrizeDrain(void);
 void StopStart(void);
 void StopEnd(void);
 u64 IsDisableZone(void);
 void SetPrizeRatio(f32 a0);
 double GetPrizeRatio(void);
 double GetLockOnRatio(void);
 double GetLockOutRange(void);
 u64 IsFreeAbility(void);
 u64 IsHideNaviMap(void);
 u64 IsDisableCampMenu(void);
 void clear(void);
 STATUS(STATUS* a0, s32 a1, s32 a2, s32 a3, u32 a4);
 ~STATUS();
 void vprintf(char* a0, char* a1);
 void idle_func(void);
 void draw_func(RECT* a0, COLOR* a1);
};
