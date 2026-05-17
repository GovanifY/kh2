#ifndef KH2_SRC_YASUI_LIBYSROMDBG_DBGMEM_HPP
#define KH2_SRC_YASUI_LIBYSROMDBG_DBGMEM_HPP

#include "../../common/types.h"

namespace YS {

    class DBGMEM {
    public:
     void Init(void);
     void Alloc(u32 a0);
     void Free(void* a0);
    };

}  // namespace YS

#endif
