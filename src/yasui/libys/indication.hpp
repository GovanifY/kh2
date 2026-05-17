#pragma once

#include "../../common/types.h"

class PLAYER;

namespace YS {

    class INDICATION {
    public:
     void init_field(void);
     void _disable(void);
     void disable(void);
     void init_area(void);
     void enable(void);
     void start(PLAYER* a0);
     void end(void);
     void exec(void);
     void show(void);
     void hide(void);
     void Disable(void);
     void Enable(void);
    };

}  // namespace YS

