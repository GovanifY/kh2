#pragma once

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

