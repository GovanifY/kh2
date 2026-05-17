#ifndef KH2_SRC_YASUI_LIBYS_WINDOW_HPP
#define KH2_SRC_YASUI_LIBYS_WINDOW_HPP

#include "../../common/types.h"

class TYPE;
class WINDOW;

namespace YS {

    class WINDOW {
    public:
     WINDOW(WINDOW* a0, TYPE a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
     ~WINDOW();
     void destroy(void);
     void draw(void);
     void close(void);
     void Init(void);
     s32 Click(s32 a0, s32 a1);
     void page_end(void);
     void update(void);
     s32 set_select(s32 a0, s32 a1, s32 a2, s32 a3);
     s32 open_window(s32 a0, s32 a1, s32 a2);
     s32 set_type(s32 a0);
     s32 set_tail(s32 a0, s32 a1, s32 a2);
     s32 set_arrow(s32 a0, s32 a1, s32 a2);
     s32 draw_anime(s32 a0, s32 a1, s32 a2);
    };

}  // namespace YS

#endif
