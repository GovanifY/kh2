#ifndef KH2_SRC_YASUI_LIBYS_SINGLETONSE_HPP
#define KH2_SRC_YASUI_LIBYS_SINGLETONSE_HPP

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

#endif
