#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"


namespace YS {

class TEST_WEAPON {
public:
    void SelectMenu(s32 a0);
    void ChangeWeaponThread(TASK* a0);
    void Init(void);
};

}  // namespace YS

