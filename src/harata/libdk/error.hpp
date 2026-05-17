#ifndef KH2_SRC_HARATA_LIBDK_ERROR_HPP
#define KH2_SRC_HARATA_LIBDK_ERROR_HPP

#include "types.h"

struct TASK;

namespace dk {

class Error {
public:
    void disable(void);
    void enable(void);
    void init(void);
    void error_task(TASK* a0);
};

}  // namespace dk

#endif
