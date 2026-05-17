#include "levelup.hpp"

namespace YS {
namespace LEVELUP {

INFO::INFO() {
    INFO_Layout* i = reinterpret_cast<INFO_Layout*>(this);
    i->v2 = 0;
    i->v0 = 0;
    i->v1 = 0;
}

}  // namespace LEVELUP
}  // namespace YS
