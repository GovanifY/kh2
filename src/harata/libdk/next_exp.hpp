#ifndef KH2_SRC_HARATA_LIBDK_NEXT_EXP_HPP
#define KH2_SRC_HARATA_LIBDK_NEXT_EXP_HPP

#include "../../common/types.h"

class NEXT_EXP;

namespace dk {

    class NEXT_EXP {
    public:
     void initNumber(void);
     void update(void);
     void draw(void);
     void create(s32 a0);
     ~NEXT_EXP();
    };

}  // namespace dk

#endif
