#ifndef KH2_SRC_NAKA_LIBKN_CHICKEN_LITTLE_HPP
#define KH2_SRC_NAKA_LIBKN_CHICKEN_LITTLE_HPP

#include "../../common/types.h"

class ChickenLittle;
class FVector;
class Friend;
class FriendAction;
class FriendParam;
class TARGET;

namespace kn {

    class ChickenLittle {
    public:
     void calc_center(void);
     void update_lockon(void);
     void exec_fps(void);
     ChickenLittle(ChickenLittle* a0, Friend* a1, FriendParam* a2);
     ~ChickenLittle();
     u64 execScriptAttack(FriendAction* a0, TARGET* a1, void** a2, bool a3);
     void start_limit(void);
     void end_limit(void);
     void get_shoot_target(void);
     void set_shoot_target(FVector* a0);
     void get_nearest_target(TARGET* a0, f32 a1, f32 a2);
    };

}  // namespace kn

#endif
