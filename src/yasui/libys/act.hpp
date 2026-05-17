#ifndef KH2_SRC_YASUI_LIBYS_ACT_HPP
#define KH2_SRC_YASUI_LIBYS_ACT_HPP

#include "../../common/types.h"

class ATTACK;
union BD_VALUE;
class DAMAGE;
class ELEM;
class SHOUT;
struct TASK;
class VMOBJ;

namespace YS {

    class ACT {
    public:
     bool callback(s32 a0, BD_VALUE* a1, s32 a2);
     void stop(void);
     u64 start(ELEM* a0);
     void clear(void);
     void start(char* a0);
     u64 check_start(void);
     bool is_damage_motion(void);
     void listen(SHOUT* a0);
     void ExecTask(TASK* a0);
     void push(char* a0);
     void child_push(char* a0);
     void wedge(char* a0);
     u64 is_exist(char* a0);
     void request(char* a0);
     void end(void);
     void exec(void);
     void damage(DAMAGE* a0);
     void reflect(ATTACK* a0, ATTACK* a1);
     void ShoutCall(char* a0, VMOBJ* a1, f32 a2);
     void shout(char* a0, f32 a1);
     void pri_start(char* a0);
     u64 can_control(void);
     void Init(void);
    };

}  // namespace YS

#endif
