#ifndef KH2_SRC_TOZAWA_MENU_OBJ_HPP
#define KH2_SRC_TOZAWA_MENU_OBJ_HPP

#include "types.h"

namespace dk {
class Sprite;
}

namespace Tz {

class LayMsg;

class MenuObj {
public:
    void SetAction(s32, s32, s32);
    void SetTransZ(s32, f32);
    void SetRotX(s32, f32);
    void SetRotY(s32, f32);
    void SetSyncLayMsg(s32, LayMsg*);
    void SetSyncSprite(s32, dk::Sprite*);
};

}  // namespace Tz

#endif
