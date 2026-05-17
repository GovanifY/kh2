#pragma once

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

