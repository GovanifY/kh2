#ifndef KH2_SRC_WORLDMAP_OBJWIDGET_HPP
#define KH2_SRC_WORLDMAP_OBJWIDGET_HPP

#include "../common/types.h"

class COLOR;
class FVector;
class Position;

namespace worldmap {

class ObjWidget {
public:
    ObjWidget(u32);
    void draw(Position, COLOR);
    void setRootPosition(FVector*);
    void setRootRot(FVector*);
    void debugControl();
    ~ObjWidget();
};

}  // namespace worldmap

#endif
