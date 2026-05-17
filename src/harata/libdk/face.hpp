#pragma once

#include "../../common/types.h"

class FACE;
class OBJ;

namespace dk {

    class FACE {
    public:
     void update(void);
     void draw(void);
     u64 getFaceSed(void** a0, OBJ* a1);
     void create(s32 a0, s32 a1, OBJ* a2, s32 a3, s32 a4, s32 a5);
     void setFaceType(s32 a0, s32 a1);
     void setFaceType(s32 a0);
     void reload(OBJ* a0, s32 a1);
     void createSummon(s32 a0, void* a1, void* a2, s32 a3, s32 a4, s32 a5);
     ~FACE();
    };

}  // namespace dk

