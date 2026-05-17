#include "bgm.hpp"

namespace dk {

extern "C" u32 func_00242ea8(...);
extern "C" void func_002ba848(u32);

void BGM::fieldExit() {
    if (func_00242ea8() != 0u) {
        func_002ba848(240u);
        return;
    }
    func_002ba848(960u);
}

}  // namespace dk
