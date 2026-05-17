#ifndef KH2_SRC_YASUI_LIBYS_COMMAND_HPP
#define KH2_SRC_YASUI_LIBYS_COMMAND_HPP

#include "../../common/types.h"

class COMMAND_ELEM;
class TARGET;

namespace YS {

    class COMMAND {
    public:
     void clear(void);
     void set(s32 a0, TARGET* a1, COMMAND_ELEM* a2);
    };

}  // namespace YS

#endif
