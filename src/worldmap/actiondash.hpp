#ifndef KH2_SRC_WORLDMAP_ACTIONDASH_HPP
#define KH2_SRC_WORLDMAP_ACTIONDASH_HPP

#include "../common/types.h"

class OBJ;

namespace worldmap {

class ActionDash {
public:
    void start(OBJ*);
    void end(OBJ*);
    void control(OBJ*);
    void calc_movement(OBJ*);
    void party_jump(OBJ*, bool);
    ~ActionDash();
};

}  // namespace worldmap

#endif
