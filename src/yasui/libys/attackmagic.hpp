#ifndef KH2_SRC_YASUI_LIBYS_ATTACKMAGIC_HPP
#define KH2_SRC_YASUI_LIBYS_ATTACKMAGIC_HPP

#include "../../common/types.h"

class ATTACK_MAGIC;
class ATTACK_WORK_MANAGER;
class BTLOBJ;
class EFFECT;
class FVector;
class OBJ;

namespace YS {

    class ATTACK_MAGIC {
    public:
     ATTACK_MAGIC(ATTACK_MAGIC* a0, BTLOBJ* a1, s32 a2, s32 a3, s32 a4, s32 a5);
     void get_dir(OBJ* a0);
     void set_pos(FVector* a0);
     void make_work(ATTACK_WORK_MANAGER* a0);
     void set_line(FVector* a0, FVector* a1);
     void get_reflect_vector(void);
     void set_size(f32 a0, f32 a1);
     void set_reaction_command(void* a0, s32 a1, f32 a2, f32 a3);
     void set_effect(EFFECT* a0);
     void set_time(f32 a0, f32 a1, f32 a2);
     ~ATTACK_MAGIC();
     void get_pos(void);
    };

}  // namespace YS

#endif
