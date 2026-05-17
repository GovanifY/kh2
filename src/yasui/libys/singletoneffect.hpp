#ifndef KH2_SRC_YASUI_LIBYS_SINGLETONEFFECT_HPP
#define KH2_SRC_YASUI_LIBYS_SINGLETONEFFECT_HPP

#include "../../common/types.h"

class OBJ;

namespace YS {

    class SINGLETON_EFFECT {
    public:
     void start_bind(s32 a0, OBJ* a1);
     void kill(void);
     void loop_end_kill(void);
     void exec(void);
     void loop_end(void);
    };

}  // namespace YS

#endif
