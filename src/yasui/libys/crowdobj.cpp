#include "types.h"


namespace YS {

} // namespace YS

class CROWDOBJ;
class OBJENTRY;

class CROWDOBJ {
public:
 void _OVR_exec(void);
 void inc_child(void);
 void dec_child(void);
 CROWDOBJ(CROWDOBJ* a0, OBJENTRY* a1, s32 a2, s32 a3);
};
