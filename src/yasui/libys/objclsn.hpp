#pragma once

#include "../../common/types.h"

class Aabbox;
class COLLISION;

namespace YS {

    class OBJCLSN {
    public:
     void free(void);
     void set(void);
     void calc_bounding_box(Aabbox* a0);
     void make_space(COLLISION* a0);
     void draw(u32 a0);
    };

}  // namespace YS

