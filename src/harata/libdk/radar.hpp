#pragma once

#include "../../common/types.h"

class MapFile;
class Radar;

namespace dk {

    class Radar {
    public:
     void create(void* a0);
     void update(void);
     void draw(void);
     ~Radar();
     void on(void);
     void off(void);
     s32 init(MapFile* a0);
     void exit(void);
     void debugOn(void);
    };

}  // namespace dk

