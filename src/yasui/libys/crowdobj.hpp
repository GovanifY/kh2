#ifndef KH2_SRC_YASUI_LIBYS_CROWDOBJ_HPP
#define KH2_SRC_YASUI_LIBYS_CROWDOBJ_HPP

#include "../../common/types.h"

class CROWDOBJ;
class OBJENTRY;

namespace YS {

    class CROWDOBJ {
    public:
     void _OVR_exec(void);
     void inc_child(void);
     void dec_child(void);
     CROWDOBJ(CROWDOBJ* a0, OBJENTRY* a1, s32 a2, s32 a3);
    };

}  // namespace YS

#endif
