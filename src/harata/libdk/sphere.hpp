#pragma once

#include "../../common/types.h"

class FVector;
class Line;
class Plane;
class Polygon;

namespace dk {

    class Sphere {
    public:
     u64 testPlane(Plane* a0, float* a1);
     bool testPlaneDouble(Plane* a0, float* a1);
     void testFace(Polygon* a0, Plane* a1, float* a2, FVector* a3);
     u64 testEdge(Polygon* a0, FVector* a1);
     bool testPoint(FVector* a0, float* a1);
     void testLine(Line* a0, FVector* a1);
     u64 testNearVertex(Polygon* a0, FVector* a1);
    };

}  // namespace dk

