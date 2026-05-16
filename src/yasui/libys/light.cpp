#include "types.h"

namespace YS {

extern f32 D_0034a998 asm("D_0034a998");
extern f32 D_0034a99c asm("D_0034a99c");

class LIGHT {
public:
    static void fadeout(f32);
    static void fadein(f32);
};

void LIGHT::fadeout(f32 value) { D_0034a998 = value; }

void LIGHT::fadein(f32 value) { D_0034a99c = value; }

}  // namespace YS
