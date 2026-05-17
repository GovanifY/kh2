#ifndef KH2_SRC_HARATA_LIBDK_COMMAND_DRAW_HPP
#define KH2_SRC_HARATA_LIBDK_COMMAND_DRAW_HPP

#include "../../common/types.h"

struct TASK;
class COMMAND_ELEM;
class COMMAND_MENU;
class COMMAND_ONE;
class COMMAND_SLOT;
class MESSAGE;
class PLAYER_COMMAND;

namespace dk {

class COMMAND_DRAW {
public:
    static u32 getSqd();
    u32 getShortCutType();
    void createBG(s32);
    void create(PLAYER_COMMAND*);
    s32 open(s32, s32, COMMAND_SLOT*, bool, s32, s32, MESSAGE*, s32, s32, f32);
    void recom(s32);
    void drawCurrentIcon(COMMAND_MENU*, s32, s32, bool, u32, COMMAND_ELEM*, COMMAND_ONE*);
    void checkOverRide(COMMAND_SLOT*, s32, s32, bool*, s32, int*, int*);
    void drawCurrent(COMMAND_MENU*, s32, s32, bool, s32, s32, s32, COMMAND_SLOT*);
    u64 getTitleSeq(s32, s32, bool*, s32, int*, int*);
    void drawCommandPage(COMMAND_MENU*, s32, s32, bool);
    u32 isInsertSkipCommand();
    void restartBG();
    u64 is_Command_Skip();
    u64 isCommandSkip();
    void drawBG();
    void shortCut(COMMAND_MENU*, bool);
    void resetBGskip();
    void initSpecialCommand();
    void setBGskip();
    void resetSpecialCommandImage();
    void resetCommandImageTask(TASK*);
    COMMAND_DRAW();
    void update();
    s32 off();
    void start(PLAYER_COMMAND*);
    u32 on();
    void reStart();
    s32 leaveAll();
    void exit();
    u32 drawStart();
    void drawEnd();
    void setAlpha(f32);
    void setSpecialCommandImage(void*, void*);
    void setCommandImage(void*, void*);
    void resetCommandImage();
    u32 isSpecialCommand();
    ~COMMAND_DRAW();
};

}  // namespace dk

#endif
