#include "mapcolor.hpp"

namespace dk {

extern u32 D_004f3694 asm("D_004f3694");



void* MapColor::getFogDefault() { return &D_004f3694; }

}  // namespace dk
