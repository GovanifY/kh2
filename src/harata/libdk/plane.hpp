#ifndef KH2_SRC_HARATA_LIBDK_PLANE_HPP
#define KH2_SRC_HARATA_LIBDK_PLANE_HPP

#include "../../common/types.h"

class FVector;
class Plane;

namespace dk {

    class Plane {
    public:
     Plane(Plane* a0, FVector* a1, FVector* a2, FVector* a3);
     u64 classifyPoint(FVector* a0, FVector* a1, FVector* a2);
    };

}  // namespace dk

#endif
