#include "types.h"


namespace worldmap {

} // namespace worldmap

class COLOR;
class FVector;
class ObjWidget;
class Position;

class ObjWidget {
public:
 ObjWidget(ObjWidget* a0, u32 a1);
 void draw(Position a0, COLOR a1);
 void setRootPosition(FVector* a0);
 void setRootRot(FVector* a0);
 void debugControl(void);
 ~ObjWidget();
};
