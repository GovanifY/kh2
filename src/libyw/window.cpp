#include "types.h"


class COLOR;
class EVENT;
class RECT;
struct TASK;
class TYPE;
class WINDOW;
class Window;

class WINDOW {
public:
 WINDOW(WINDOW* a0, char* a1, s32 a2, s32 a3, s32 a4, s32 a5, u32 a6);
 void fix_size(void);
 void set_min_size(s32 a0, s32 a1);
 void set_max_size(s32 a0, s32 a1);
 void iconify(void);
 void deiconify(void);
 void draw_icon_func(RECT* a0, COLOR* a1);
 void idle_func(void);
 void focus_func(EVENT a0, s32 a1, s32 a2);
 void draw_func(RECT* a0, COLOR* a1);
 WINDOW(WINDOW* a0, TYPE a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
 ~WINDOW();
 void destroy(void);
 void draw(void);
 void close(void);
 void Init(void);
 s32 Click(s32 a0, s32 a1);
 ~WINDOW();
 void page_end(void);
 void update(void);
 s32 set_select(s32 a0, s32 a1, s32 a2, s32 a3);
 s32 open_window(s32 a0, s32 a1, s32 a2);
 s32 set_type(s32 a0);
 s32 set_tail(s32 a0, s32 a1, s32 a2);
 s32 set_arrow(s32 a0, s32 a1, s32 a2);
 s32 draw_anime(s32 a0, s32 a1, s32 a2);
};

class Window {
public:
 Window();
 ~Window();
 u64 isExist(void);
 void execTask(TASK* a0);
};
