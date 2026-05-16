#include "types.h"


namespace YS {

} // namespace YS

class AREA;
class JUMPER;

class EVENT_SKIP {
public:
 void ResetSkipFlag(void);
 void FieldInit(void);
 u64 IsSkip(AREA* a0, JUMPER* a1);
 void SetSkipFlag(void);
};
