#include "stitch.hpp"

namespace kn {

extern void Stitch_update_obj_pos(void*) asm("_ZN2kn6Stitch14update_obj_posEv");



void Stitch::post_exec() { Stitch_update_obj_pos(this); }

}  // namespace kn
