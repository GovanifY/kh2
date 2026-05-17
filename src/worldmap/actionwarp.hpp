#ifndef KH2_SRC_WORLDMAP_ACTIONWARP_HPP
#define KH2_SRC_WORLDMAP_ACTIONWARP_HPP

#include "../common/types.h"

class OBJ;

namespace worldmap {

class ActionWarp {
public:
    void start(OBJ*);
    void control(OBJ*);
    void calc_movement(OBJ*);
    ~ActionWarp();
};

}  // namespace worldmap

#endif
