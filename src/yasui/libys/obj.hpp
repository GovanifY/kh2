#pragma once

#include "../../common/types.h"

namespace kn {
class FMatrix;
}

namespace YS {

    class OBJ {
    public:
        static u32 GetPlayer();
        void get_jump_height();
        u32 get_unit_arg(int);
        u32 get_appear_way();
        u32 get_serial();
        void set_unit_arg(int, int);
        u32 is_culling();
        u32 get_ground();
        u32 get_type();
        u32 get_entry_id();
        u32 get_part_num();
        u32 get_sub_type();
        u32 get_skeleton_num();
        u32 is_xyzrot();
        u32 can_capture_control();
        u32 is_ghost();
        u32 is_attach();
        u32 is_leave();
        u32 is_hover();
        void attach_camera(kn::FMatrix*);
        u32 is_updown();
        static u32 IsKinoko(int);
    };

}  // namespace YS

