#ifndef KH2_SRC_YASUI_LIBYS_LINKFLAG_HPP
#define KH2_SRC_YASUI_LIBYS_LINKFLAG_HPP

#include "../../common/types.h"

namespace YS {

    class LINK_FLAG {
    public:
     bool is_ok(void);
     void exec(void);
     void Init(void* a0);
     void Check(void);
    };

}  // namespace YS

#endif
