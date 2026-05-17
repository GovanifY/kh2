#pragma once

#include "../../common/types.h"

class FVector;
class SINGLETON_SE;

namespace YS {

    class SINGLETON_SE {
    public:
     SINGLETON_SE();
     ~SINGLETON_SE();
     void exec(FVector* a0);
    };

}  // namespace YS

