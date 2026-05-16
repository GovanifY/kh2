#include "types.h"


namespace YS {

} // namespace YS

class COMMAND_ELEM;
class OBJ;
class PLAYER;
class TARGET;

class COMMAND_SLOT {
public:
 u64 CanDrive(COMMAND_ELEM* a0, PLAYER* a1);
 void clear(void);
 u64 GetStatus(COMMAND_ELEM* a0, OBJ* a1, TARGET* a2);
 void set(COMMAND_ELEM* a0, OBJ* a1, TARGET* a2, s32 a3);
 u64 is_exist(void);
 bool is_beep(void);
};
