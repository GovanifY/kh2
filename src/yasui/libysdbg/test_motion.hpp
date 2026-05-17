#pragma once

#include "../../common/types.h"

namespace YS {

class OBJ;

class TEST_MOTION {
public:
    TEST_MOTION(TEST_MOTION* a0, OBJ* a1);
    void print_info(void);
    void Open(s32 a0);
    ~TEST_MOTION();
    void Init(void);
    void Exec(void);
};

}  // namespace YS

