#ifndef KH2_SRC_YASUI_LIBYSROMDBG_NET_HPP
#define KH2_SRC_YASUI_LIBYSROMDBG_NET_HPP

#include "../../common/types.h"

class ACCEPT_TABLE;

namespace YS {

    class NET {
    public:
     void AddAcceptCallback(ACCEPT_TABLE* a0);
     void Lock(void);
     void Unlock(void);
    };

}  // namespace YS

#endif
