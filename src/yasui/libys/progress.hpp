#pragma once

#include "../../common/types.h"

namespace YS {

class PROGRESS {
public:
    static u32 CheckFlag(s32 flag);
    static u32 IsSecond();
    static u32 CanOpenCampMenu();
    static u32 CanDrive();
};

}  // namespace YS

