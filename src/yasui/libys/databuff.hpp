#pragma once

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

