#include "types.h"


namespace dk {

} // namespace dk

class BoundingBox;
class FMatrix;
class FVector;
class uchar;

class Polygon {
public:
 u64 testInPointYAxis(FVector* a0);
 u64 testInPoint(FVector* a0, FVector* a1);
 void generateVertex8(FVector* a0);
 void drawLine(BoundingBox* a0, uchar a1, uchar a2, uchar a3, FMatrix* a4);
 void drawLine(BoundingBox* a0, uchar a1, uchar a2, uchar a3);
};
