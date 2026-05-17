#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_WEAPON_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_WEAPON_HPP

#include "types.h"

struct TASK;

namespace YS {

class TEST_WEAPON {
public:
    void SelectMenu(s32 a0);
    void ChangeWeaponThread(TASK* a0);
    void Init(void);
};

}  // namespace YS

#endif
