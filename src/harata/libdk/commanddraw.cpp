#include "types.h"


namespace dk {

} // namespace dk

class COMMAND_DRAW;
class COMMAND_ELEM;
class COMMAND_MENU;
class COMMAND_ONE;
class COMMAND_SLOT;
class MESSAGE;
class PLAYER_COMMAND;
struct TASK;

class COMMAND_DRAW {
public:
 u64 getSqd(void);
 u64 getShortCutType(void);
 void createBG(s32 a0);
 void create(PLAYER_COMMAND* a0);
 s32 open(s32 a0, s32 a1, COMMAND_SLOT* a2, bool a3, s32 a4, s32 a5, MESSAGE* a6, s32 a7, s32 a8, f32 a9);
 void recom(s32 a0);
 void drawCurrentIcon(COMMAND_MENU* a0, s32 a1, s32 a2, bool a3, u32 a4, COMMAND_ELEM* a5, COMMAND_ONE* a6);
 void checkOverRide(COMMAND_SLOT* a0, s32 a1, s32 a2, bool* a3, s32 a4, int* a5, int* a6);
 void drawCurrent(COMMAND_MENU* a0, s32 a1, s32 a2, bool a3, s32 a4, s32 a5, s32 a6, COMMAND_SLOT* a7);
 u64 getTitleSeq(s32 a0, s32 a1, bool* a2, s32 a3, int* a4, int* a5);
 void drawCommandPage(COMMAND_MENU* a0, s32 a1, s32 a2, bool a3);
 u64 isInsertSkipCommand(void);
 void restartBG(void);
 u64 is_Command_Skip(void);
 u64 isCommandSkip(void);
 void drawBG(void);
 void shortCut(COMMAND_MENU* a0, bool a1);
 void resetBGskip(void);
 void initSpecialCommand(void);
 void setBGskip(void);
 void resetSpecialCommandImage(void);
 void resetCommandImageTask(TASK* a0);
 COMMAND_DRAW();
 void update(void);
 s32 off(void);
 void start(PLAYER_COMMAND* a0);
 u32 on(void);
 void reStart(void);
 s32 leaveAll(void);
 void exit(void);
 u32 drawStart(void);
 void drawEnd(void);
 void setAlpha(f32 a0);
 void setSpecialCommandImage(void* a0, void* a1);
 void setCommandImage(void* a0, void* a1);
 void resetCommandImage(void);
 u64 isSpecialCommand(void);
 ~COMMAND_DRAW();
};
