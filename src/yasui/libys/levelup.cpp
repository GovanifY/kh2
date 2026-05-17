#include "levelup.hpp"

namespace YS {
namespace LEVELUP {

struct INFO_Layout {
    u32 v0;
    u32 v1;
    u32 v2;
};

INFO::INFO() {
    INFO_Layout* i = reinterpret_cast<INFO_Layout*>(this);
    i->v2 = 0;
    i->v0 = 0;
    i->v1 = 0;
}

}  // namespace LEVELUP
}  // namespace YS
