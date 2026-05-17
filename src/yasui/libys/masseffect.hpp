#pragma once

#include "../../common/types.h"

class FMatrix;
class FVector;
class FuncDef56;
class FuncDef57;
class MANAGER;
class MASSEFFECT;
class REFERENCE;
class SLIST;
class ZSORT;

namespace YS {

    class MASSEFFECT {
    public:
     ~MASSEFFECT();
     MASSEFFECT(MASSEFFECT* a0, MANAGER* a1, FVector* a2, FuncDef56* a3);
     MASSEFFECT(MASSEFFECT* a0, MANAGER* a1, FVector* a2, FuncDef57* a3);
     u64 exec(void);
     void link_zsort_list(SLIST* a0, ZSORT* a1, FMatrix* a2);
     void make_reference(REFERENCE* a0);
    };

}  // namespace YS

