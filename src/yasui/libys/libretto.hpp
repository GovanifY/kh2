#pragma once

#include "../../common/types.h"

class CODE;
class FuncDef54;
class LIBRETTO;
struct TASK;

namespace YS {

    class LIBRETTO {
    public:
     u64 CodeParser(CODE* a0, void* a1);
     void init(s32 a0, FuncDef54* a1);
     u64 exec(TASK* a0);
     void Read(void);
     void Init(void);
     void Ensure(void);
     void Free(LIBRETTO* a0);
    };

}  // namespace YS

