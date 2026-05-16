#include "types.h"


namespace YS {

} // namespace YS

class ATTACK;
class ATTACKPARAM;
class ATTACK_CHECK;
class BTLOBJ;

class ATTACK_CHECK {
public:
 void exec(void);
 void hit_interval_attack(ATTACK* a0, ATTACKPARAM* a1);
 ATTACK_CHECK(ATTACK_CHECK* a0, BTLOBJ* a1);
 ~ATTACK_CHECK();
 bool is_strike(ATTACK* a0);
 u64 is_hit(ATTACK* a0);
 s32 hit(ATTACK* a0, bool* a1);
 void unhit(ATTACK* a0);
 void Init(void);
 s32 NewAttackId(void);
 void FreeAttackId(s32 a0);
 s32 NewComboGroup(void);
 void Exec(void);
};
