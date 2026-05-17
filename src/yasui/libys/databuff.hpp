#ifndef KH2_SRC_YASUI_LIBYS_DATABUFF_HPP
#define KH2_SRC_YASUI_LIBYS_DATABUFF_HPP

#include "../../common/types.h"

namespace YS {

    class DATABUFF {
    public:
     void Open(void);
     void Close(void);
     u64 Read(char* a0);
     u64 ReadBar(char* a0);
    };

}  // namespace YS

#endif
