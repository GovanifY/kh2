#include "light.hpp"

namespace YS {

extern f32 D_0034a998 asm("D_0034a998");
extern f32 D_0034a99c asm("D_0034a99c");



void LIGHT::fadeout(f32 value) { D_0034a998 = value; }

void LIGHT::fadein(f32 value) { D_0034a99c = value; }

}  // namespace YS
