#include "types.h"


namespace dk {

} // namespace dk

class FVector;
class Plane;
class Polygon;

class Ray {
public:
 u64 intersectPolygon(Polygon* a0, Plane* a1, FVector* a2);
};
