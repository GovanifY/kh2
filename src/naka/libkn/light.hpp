#pragma once

#include "../../common/types.h"

class FMatrix;
class FVector;
class Light;
class LightParam;
class ProjectionCamera;
class SHADOW_SIZE;

namespace kn {

    class Light {
    public:
     Light();
     ~Light();
     void setPosition(FVector* a0);
     void setColor(FVector* a0);
     void getLightParam(FMatrix* a0, LightParam* a1);
     void calcShadowMatrix(FVector* a0, ProjectionCamera* a1, ProjectionCamera* a2, SHADOW_SIZE a3);
     void setAmbientColor(FVector* a0);
    };

}  // namespace kn

