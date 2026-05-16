#include "types.h"


namespace YS {

} // namespace YS

class FVector;

class BGHIT {
public:
 void check_line(FVector* a0, FVector* a1, s32 a2);
 void get_normal(void);
 u64 get_kind(void);
};
