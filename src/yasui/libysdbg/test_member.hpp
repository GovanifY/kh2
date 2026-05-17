#pragma once

#include "../../common/types.h"

class EVENT;
class TEST_MEMBER;

namespace YS {

    class TEST_MEMBER {
    public:
     TEST_MEMBER();
     void Open(s32 a0);
     void SelectCallback(EVENT a0, s32 a1, void* a2);
     void Init(void);
     ~TEST_MEMBER();
    };

}  // namespace YS

