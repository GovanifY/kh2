#ifndef KH2_SRC_RIKEDA_ADVICE_HPP
#define KH2_SRC_RIKEDA_ADVICE_HPP

#include "../common/types.h"

class ADVICE;

namespace ryj {

    class ADVICE {
    public:
     void Load(void);
     u32 GetNum(void);
     s32 Get(s32 a0);
     bool IsUse(s32 a0);
     void Use(ADVICE* a0);
    };

}  // namespace ryj

#endif
