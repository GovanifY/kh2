#include "path.hpp"

namespace YS {
struct UNIT_DATA_PATH;
}

namespace Ti {



u32 Path::check_data(const YS::UNIT_DATA_PATH* data) {
    u32 v = *(u32*)((u32)this + 144);
    v ^= (u32)data;
    return (v < (u32)1);
}

}  // namespace Ti
