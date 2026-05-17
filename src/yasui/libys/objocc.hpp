#pragma once

#include "../../common/types.h"

class OBJ;
class OBJOCC;

namespace YS {

    class OBJOCC {
    public:
     ~OBJOCC();
     void init(void* a0, bool a1);
     void set_matrix(OBJ* a0);
     void disable(s32 a0);
     void disable_all(void);
     void enable(s32 a0);
     void enable_all(void);
     void Init(void);
    };

}  // namespace YS

