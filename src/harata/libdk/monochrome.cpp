#include "monochrome.hpp"

namespace dk {

extern u32 D_00347ff8 asm("D_00347ff8");



bool Monochrome::isMonochrome() { return D_00347ff8 == 1; }

}  // namespace dk
