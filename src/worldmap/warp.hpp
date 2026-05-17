#ifndef KH2_SRC_WORLDMAP_WARP_HPP
#define KH2_SRC_WORLDMAP_WARP_HPP

#include "../common/types.h"

class TARGET;

namespace worldmap {

class Player;

class Warp {
public:
    void start(Player*, TARGET*);
    void exec(Player*);
};

}  // namespace worldmap

#endif
