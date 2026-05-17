#pragma once

#include "../../common/types.h"

class ATTACK;
class ATTACKPARAM;
class BTLOBJ;
class FVector;
class OBJ;
class STDOBJ;
struct TASK;

namespace YS {

    class ATTACK {
    public:
     void SetHitmarkPos(FVector* a0, FVector* a1);
     s32 force_strike(BTLOBJ* a0, ATTACKPARAM* a1, s32 a2);
     u64 is_strike(BTLOBJ* a0);
     s32 strike(BTLOBJ* a0, s32 a1, s32 a2);
     u64 is_guard(void);
     void ExecTask(TASK* a0);
     void refresh(void);
     ~ATTACK();
     void set_team(s32 a0);
     ATTACK(ATTACK* a0, BTLOBJ* a1, STDOBJ* a2, s32 a3, s32 a4, s32 a5, s32 a6);
     void get_pos(void);
     void get_dir(OBJ* a0);
     s32 is_hit(void);
     void get_reflect_dir(ATTACK* a0);
     u64 is_exist(void);
     void destroy(void);
     void is_finish(void);
     void Init(void);
     void Ensure(void);
     u32 Each(ATTACK* a0);
     void EachMagic(ATTACK* a0);
     u64 Strike(BTLOBJ* a0, s32 a1, BTLOBJ* a2, FVector* a3, bool a4);
    };

}  // namespace YS

