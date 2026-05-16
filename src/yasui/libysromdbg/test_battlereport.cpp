#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class ...;
class COLOR;
class RECT;
class TEST_BATTLEREPORT;

class TEST_BATTLEREPORT {
public:
 void printf(char* a0, ...);
 void draw_func(RECT* a0, COLOR* a1);
 void Open(s32 a0);
 void Init(void);
 ~TEST_BATTLEREPORT();
};
