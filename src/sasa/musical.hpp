#pragma once

#include "../common/types.h"

namespace sa {

    class MUSICAL {
    public:
     s32 getRhythm(void);
     void setSuccessNg(void);
     void setSuccess(void);
     u32 getSuccessNg(void);
     void addScore(s32 a0);
     void setScore(s32 a0);
     u32 getScore(void);
     void setOkJumpFrame(s32 a0);
     u32 getStage(void);
     s32 result(void);
     void clearCombo(void);
     void incCombo(void);
    };

}  // namespace sa

