#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace dk {

class Error {
public:
    void disable(void);
    void enable(void);
    void init(void);
    void error_task(TASK* a0);
};

}  // namespace dk

