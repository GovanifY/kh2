#ifndef KH2_SRC_LIBYW_MOUSE_HPP
#define KH2_SRC_LIBYW_MOUSE_HPP

#include "../common/types.h"

namespace YW {

class MOUSE {
public:
    u64 read();
    void Init();
};

}  // namespace YW

#endif
