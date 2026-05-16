#include "types.h"


namespace YS {

} // namespace YS

class EFFECT;
class OBJENTRY;
class PAX;

class OBJDATA {
public:
 void clear(void);
 void _set(void);
 u64 CanAlloc(u32 a0, OBJENTRY* a1);
 void free(void);
 void set(u32 a0, OBJENTRY* a1);
 void reset(s32 a0);
 u32 get_knm(void);
 u32 get_knt(void);
 u32 get_kna(s32 a0, s32 a1);
 void start_model_effect(void* a0, PAX* a1, EFFECT** a2);
};
