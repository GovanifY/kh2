#include "types.h"


namespace dk {

} // namespace dk

class FVector;

class POLYGONSE {
public:
 void init(void);
 void destroy(void);
 void createSe(s32 a0, s32 a1);
 void calc(s32 a0, FVector* a1, bool* a2);
};
