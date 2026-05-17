#ifndef KH2_SRC_HARATA_LIBDK_GET_MUNNY_HPP
#define KH2_SRC_HARATA_LIBDK_GET_MUNNY_HPP

#include "../../common/types.h"

class GET_MUNNY;

namespace dk {

    class GET_MUNNY {
    public:
     void initNumber(void);
     void update(void);
     void draw(void);
     void create(s32 a0);
     ~GET_MUNNY();
    };

}  // namespace dk

#endif
