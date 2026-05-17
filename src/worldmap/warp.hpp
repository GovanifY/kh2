#pragma once

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

