#pragma once

#include "../../common/types.h"

class BATTLE_REPORT;

namespace YS {

    class BATTLE_REPORT {
    public:
      BATTLE_REPORT();
      void IncrementFriendRecov(void);
      void IncrementFormCount(s32 a0);
      void IncrementSummonCount(s32 a0);
      static s32 IsSecretMovie(void);
      static s32 IsFMSecretMovie(void);
      u64 GetResultPicture(void);
    };

}  // namespace YS

