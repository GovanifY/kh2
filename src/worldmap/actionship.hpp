#ifndef KH2_SRC_WORLDMAP_ACTIONSHIP_HPP
#define KH2_SRC_WORLDMAP_ACTIONSHIP_HPP

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

#endif
