#ifndef KH2_SRC_YASUI_LIBYS_RECOM_HPP
#define KH2_SRC_YASUI_LIBYS_RECOM_HPP

#include "../../common/types.h"

namespace YS {

    class RECOM {
    public:
     void init(void);
     void start(COMMAND_SLOT* a0);
     void release(void);
     void exec(void);
    };

}  // namespace YS

#endif
