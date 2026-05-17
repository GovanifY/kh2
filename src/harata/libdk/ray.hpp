#ifndef KH2_SRC_HARATA_LIBDK_RAY_HPP
#define KH2_SRC_HARATA_LIBDK_RAY_HPP

#include "../../common/types.h"

class FVector;
class Plane;
class Polygon;

namespace dk {

    class Ray {
    public:
     u64 intersectPolygon(Polygon* a0, Plane* a1, FVector* a2);
    };

}  // namespace dk

#endif
