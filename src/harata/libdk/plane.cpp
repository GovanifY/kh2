#include "types.h"


namespace dk {

} // namespace dk

class FVector;
class Plane;

class Plane {
public:
 Plane(Plane* a0, FVector* a1, FVector* a2, FVector* a3);
 u64 classifyPoint(FVector* a0, FVector* a1, FVector* a2);
};
