#ifndef KH2_SRC_HARATA_LIBDK_VSYNCTHREAD_HPP
#define KH2_SRC_HARATA_LIBDK_VSYNCTHREAD_HPP

#include "types.h"

namespace dk {

class FuncDef20;

class VsyncThread {
public:
    void init(void);
    s32 create(char* a0, s32 a1, FuncDef20* a2, void* a3);
    void wait(void);
    void wakeup(void);
    void isleep(void);
    void exec(void* a0);
};

}  // namespace dk

#endif
