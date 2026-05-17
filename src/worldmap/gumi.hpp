#pragma once

#include "../common/types.h"
#include "../yasui/libys/obj.hpp"

namespace worldmap {

class Gumi : public YS::OBJ {
public:
    u32 getCourse();
};

}  // namespace worldmap

