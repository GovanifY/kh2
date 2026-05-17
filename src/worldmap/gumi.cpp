#include "../common/types.h"

namespace YS {
class OBJ {
public:
    u32 get_unit_arg(s32);
};
}

namespace worldmap {

class Gumi : public YS::OBJ {
public:
    u32 getCourse();
};

u32 Gumi::getCourse() {
    return get_unit_arg(1);
}

}  // namespace worldmap
