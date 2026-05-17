#ifndef KH2_SRC_YASUI_LIBYS_CACHEBUFF_WINDOW_HPP
#define KH2_SRC_YASUI_LIBYS_CACHEBUFF_WINDOW_HPP

#include "../../common/types.h"

class CACHE_BUFF_WINDOW;

namespace YS {

    class CACHE_BUFF_WINDOW {
    public:
     void Init(void);
     CACHE_BUFF_WINDOW(CACHE_BUFF_WINDOW* a0, s32 a1, s32 a2, s32 a3, s32 a4);
     void OpenWindow(s32 a0);
     ~CACHE_BUFF_WINDOW();
    };

}  // namespace YS

#endif
