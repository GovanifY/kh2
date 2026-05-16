#include "types.h"


namespace YS {

} // namespace YS

class BATTLE_REPORT;

class BATTLE_REPORT {
public:
 BATTLE_REPORT();
 void IncrementFriendRecov(void);
 void IncrementFormCount(s32 a0);
 void IncrementSummonCount(s32 a0);
 u64 IsSecretMovie(void);
 u64 IsFMSecretMovie(void);
 u64 GetResultPicture(void);
};
