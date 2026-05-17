#pragma once

#include "../common/types.h"

class OBJ;

namespace worldmap {

class ActionShip {
public:
    void control(OBJ*);
    void calc_movement(OBJ*);
    ~ActionShip();
};

}  // namespace worldmap

