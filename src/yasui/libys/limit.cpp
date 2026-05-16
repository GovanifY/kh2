#include "types.h"


namespace YS {

} // namespace YS

class ATTACK;
class ATTACKPARAM;
union BD_VALUE;
class BTLOBJ;
class COMMAND_ELEM;
class EFFECT;
class IMAGE_DATA;
class LIMIT;
class LIMIT_TABLE;
class OBJ;
class PARTY;
class PAX;
class PLAYER;
struct TASK;

class LIMIT {
public:
 u64 is_add_time(void);
 u64 can_end(void);
 void set_special_command(s32 a0);
 void set_image(IMAGE_DATA* a0, char* a1);
 void setup(f32 a0);
 void close_gauge(void);
 void end(void);
 ~LIMIT();
 void reset_special_command(void);
 void destroy(void);
 void exec(bool a0);
 void ExecTask(TASK* a0);
 void Finalizer(TASK* a0);
 LIMIT(LIMIT* a0, LIMIT_TABLE* a1, PLAYER* a2, f32 a3);
 void motion_start(OBJ* a0, s32 a1, f32 a2);
 void camera_start(char* a0, f32 a1, bool a2);
 void start_effect(s32 a0, s32 a1, OBJ* a2);
 u32 reset_hit_counter(void);
 void Init(void);
 void Start(s32 a0, PLAYER* a1);
 u64 IsExec(void);
 void StartThread(s32 a0, BD_VALUE* a1, s32 a2);
 u64 AnmatrEffect(PAX* a0, OBJ* a1, s32 a2, EFFECT* a3);
 void AnmatrCallback(BD_VALUE* a0, s32 a1);
 void Attack(PARTY* a0, BTLOBJ* a1, ATTACK* a2, ATTACKPARAM* a3);
 s32 GetPax(void);
 void Clear(void);
 void PlayVoice(s32 a0, s32 a1, OBJ* a2);
 void ComboHit(void);
 u16 GetExecCommand(void);
 s32 GetCommandStatus(PLAYER* a0, COMMAND_ELEM* a1, s32 a2);
};
