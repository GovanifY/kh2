#pragma once

#include "../common/types.h"

class COLOR;
class DbgObjCamera;
class RECT;

namespace worldmap {

    class DbgObjCamera {
    public:
     void initialize(void);
     DbgObjCamera();
     void draw_func(RECT* a0, COLOR* a1);
     void selectCallback(s32 a0);
     ~DbgObjCamera();
    };

}  // namespace worldmap

