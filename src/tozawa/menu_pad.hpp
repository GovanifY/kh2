#ifndef KH2_SRC_TOZAWA_MENU_PAD_HPP
#define KH2_SRC_TOZAWA_MENU_PAD_HPP

#include "types.h"

namespace Tz {

class MenuPad {
public:
    void Push(s32 a0);
    void PushEnable(void);
    void Pop(void);
    void Reset(void);
};

}  // namespace Tz

#endif
