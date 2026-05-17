#ifndef KH2_SRC_HARATA_LIBDK_LAYOUT_HPP
#define KH2_SRC_HARATA_LIBDK_LAYOUT_HPP

#include "../../common/types.h"

namespace dk {

class Layout {
public:
    void destroy(void);
    void setPos(f32 a0, f32 a1);
    void init(void);
    void exit(void);
    ~Layout();
};

}  // namespace dk

#endif
