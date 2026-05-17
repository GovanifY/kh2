#ifndef KH2_SRC_YASUI_LIBYS_PROGRESS_HPP
#define KH2_SRC_YASUI_LIBYS_PROGRESS_HPP

#include "types.h"

namespace YS {

class PROGRESS {
public:
    static u32 CheckFlag(s32 flag);
    static u32 IsSecond();
    static u32 CanOpenCampMenu();
    static u32 CanDrive();
};

}  // namespace YS

#endif
