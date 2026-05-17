#include "./types.h"
#include "task.hpp"


class GAME_MODE;

namespace GAME_MODE {

void disable(void);
void start(void);
void initialize(TASK* a0);
void finalize(TASK* a0);
s32 getExecMode(GAME_MODE** a0);
void enable(void);
s32 getCurrent(void);
void ExecTask(TASK* a0);

} // namespace GAME_MODE
