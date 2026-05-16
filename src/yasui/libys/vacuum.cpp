#include "types.h"


namespace YS {

} // namespace YS

class FVector;
class VACUUM;

class VACUUM {
public:
 VACUUM(VACUUM* a0, FVector* a1, f32 a2);
 ~VACUUM();
 void Init(void);
 void Exit(void);
};
