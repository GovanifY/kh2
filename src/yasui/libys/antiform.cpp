#include "types.h"


namespace YS {

} // namespace YS

class FORMRAM;
class SORA;

class ANTI_FORM {
public:
 u64 IsAnti(SORA* a0, FORMRAM* a1);
 u64 IsFinal(SORA* a0);
 s32 CheckForm(SORA* a0, s32 a1);
};
