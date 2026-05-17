#ifndef KH2_SRC_YASUI_LIBYS_BGHIT_HPP
#define KH2_SRC_YASUI_LIBYS_BGHIT_HPP

#include "../../common/types.h"

class FVector;

namespace YS {

    class BGHIT {
    public:
     void check_line(FVector* a0, FVector* a1, s32 a2);
     void get_normal(void);
     u64 get_kind(void);
    };

}  // namespace YS

#endif
