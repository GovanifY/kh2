#include "../../common/types.h"

namespace dk {

extern "C" void drawFrameEnable_clear_raw(void) asm("_Z13func_0014df98v");

void clearDrawFrameEnable() { drawFrameEnable_clear_raw(); }

}  // namespace dk
