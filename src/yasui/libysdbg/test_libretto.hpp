#pragma once

#include "../../common/types.h"

class CODE;
class LIBRETTO;
struct TASK;

namespace YS {

    class TEST_LIBRETTO {
    public:
     void Open(s32 a0);
     void ExecThread(TASK* a0);
     u64 Callback(CODE* a0, LIBRETTO* a1);
     void Init(void);
    };

}  // namespace YS

