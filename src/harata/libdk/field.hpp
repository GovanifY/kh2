#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace dk {

class FuncDef8;
class FuncDef9;

class Field {
public:
    void WorldMapStart(s32 a0, u32 a1);
    void TitleStart(bool a0);
    void init(void);
    void execTitle_task(TASK* a0);
};

}  // namespace dk

