#include "gumi.hpp"

namespace worldmap {

u32 Gumi::getCourse() {
    return this->get_unit_arg(1);
}

}  // namespace worldmap
