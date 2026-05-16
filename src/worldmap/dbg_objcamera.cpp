#include "types.h"


namespace worldmap {

} // namespace worldmap

class COLOR;
class DbgObjCamera;
class RECT;

class DbgObjCamera {
public:
 void initialize(void);
 DbgObjCamera();
 void draw_func(RECT* a0, COLOR* a1);
 void selectCallback(s32 a0);
 ~DbgObjCamera();
};
