#ifndef KH2_SRC_HARATA_LIBDK_DBUF_HPP
#define KH2_SRC_HARATA_LIBDK_DBUF_HPP

#include "../../common/types.h"

namespace dk {

    class Dbuf {
    public:
     void swap(void);
     void clearDrawFrame(void);
     void getDrawFrame(void);
    };

}  // namespace dk

#endif
