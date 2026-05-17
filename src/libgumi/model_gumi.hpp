#pragma once

#include "../common/types.h"

class DrawParam;
class FMatrix;
class ProjectionCamera;

namespace gm {

    class MODEL_GUMI {
    public:
     void draw(ProjectionCamera* a0, FMatrix* a1, DrawParam* a2);
     s32 get_dtexture(s32 a0);
    };

}  // namespace gm

