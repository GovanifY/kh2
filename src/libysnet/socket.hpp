#ifndef KH2_SRC_LIBYSNET_SOCKET_HPP
#define KH2_SRC_LIBYSNET_SOCKET_HPP

#include "../common/types.h"

class SOCKET;

namespace YS {

    class SOCKET {
    public:
     u64 send_commandf(char* a0, ...);
     ~SOCKET();
     u64 recv(void* a0);
    };

}  // namespace YS

#endif
