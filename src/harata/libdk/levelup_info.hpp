#pragma once

#include "../../common/types.h"

class LEVELUP_INFO;
class MESSAGE;
class WIN_COLOR;

namespace dk {

    class LEVELUP_INFO {
    public:
     void update(void);
     void create(void);
     s32 init(void);
     void exit(void);
     void on(void);
     void off(void);
     void openChara(MESSAGE* a0, MESSAGE* a1, MESSAGE* a2, s32 a3, WIN_COLOR a4);
     void openBonus(MESSAGE* a0, MESSAGE* a1, MESSAGE* a2, s32 a3, WIN_COLOR a4);
     void openForm(MESSAGE* a0, MESSAGE* a1, MESSAGE* a2, s32 a3, s32 a4);
     void openSummon(MESSAGE* a0, MESSAGE* a1, s32 a2);
     ~LEVELUP_INFO();
    };

}  // namespace dk

