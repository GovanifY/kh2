#include "types.h"


namespace YS {

} // namespace YS

class DAMAGE;
class ENEMY;
class FORMRAM;
class PLAYER;

class FORM_LEVEL {
public:
 void LevelUp(PLAYER* a0, s32 a1);
 void AddExp(PLAYER* a0, s32 a1);
 void Init(void* a0);
 void CheckBrave(ENEMY* a0, DAMAGE* a1);
 void CheckWisdomAndFinal(s32 a0, PLAYER* a1);
 void CheckMaster(s32 a0, PLAYER* a1);
 void CheckLimit(PLAYER* a0, s32 a1);
 s32 GetExp(s32 a0, FORMRAM* a1);
 s32 GetSummonExp(void);
};
