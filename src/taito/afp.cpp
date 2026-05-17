#include "afp.hpp"

namespace Ti {


s32 Afp::getCount(void* p) {
    (void)p;
    return reinterpret_cast<AfpLayout*>(this)->count;
}
}  // namespace Ti
