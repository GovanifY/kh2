#pragma once

#include "../common/types.h"

namespace YS {
class OBJ;
}

namespace sa {

class EVENT {
public:
    static u32 isLK();
    static u32 isLM();
    static u32 isSceneEventExec();
    static void wide_on();
    static void readWaitInit();
    void setActorParam(YS::OBJ*);
};

}  // namespace sa

