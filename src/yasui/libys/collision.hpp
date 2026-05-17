#pragma once

#include "../../common/types.h"

class COLLISION;
class COLLISION_ELEM;
class FVector;
class OBJ;

namespace YS {

    class COLLISION {
    public:
     void check_ellipsoid_ellipsoid(COLLISION* a0);
     void check_ellipsoid_column(COLLISION* a0);
     void avoid_ellipsoid_ellipsoid(COLLISION* a0, FVector* a1);
     void set(OBJ* a0, COLLISION_ELEM* a1);
     void make(s32 a0, f32 a1, f32 a2);
     void get_dist(FVector* a0);
     u64 check(COLLISION* a0);
     void avoid(COLLISION* a0, FVector* a1);
     void draw(u32 a0, s32 a1);
    };

}  // namespace YS

