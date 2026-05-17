#pragma once

#include "../../common/types.h"

struct TASK;

namespace YS {

class TEST_WEAPON {
public:
    void SelectMenu(s32 a0);
    void ChangeWeaponThread(TASK* a0);
    void Init(void);
};

}  // namespace YS

