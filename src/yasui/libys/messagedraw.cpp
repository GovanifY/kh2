#include "types.h"


namespace YS {

} // namespace YS

class ALIGN;
class ENV;
class MESSAGE;
class MESSAGEDRAW;
class SIZE;
class TYPE;
class WINDOW;

class MESSAGEDRAW {
public:
 void set_page(MESSAGE* a0);
 s32 draw_letter(ENV* a0, s32 a1, s32 a2, s32 a3);
 u32 draw_line(ENV* a0, MESSAGE* a1);
 void set_font_size(s32 a0);
 MESSAGEDRAW(MESSAGEDRAW* a0, TYPE a1, MESSAGE* a2, s32 a3, ALIGN a4);
 void AlignDrawPos(ALIGN a0, SIZE* a1, int* a2, int* a3);
 void draw(s32 a0, s32 a1, u32 a2);
 void set_window(WINDOW* a0);
 bool next_page(void);
 void set_line_space(s32 a0);
 void check_open_window(void);
 void Draw(TYPE a0, MESSAGE* a1, s32 a2, s32 a3, u32 a4, s32 a5, ALIGN a6);
};
