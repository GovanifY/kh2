#ifndef KH2_SRC_YASUI_LIBYSDBG_ENTRY_SELECTION_HPP
#define KH2_SRC_YASUI_LIBYSDBG_ENTRY_SELECTION_HPP

#include "../../common/types.h"

class ENTRY_SELECTION;
class EVENT;
class FuncDef48;
class FuncDef49;
class OBJENTRY_DATA;
class WINDOW;

namespace YS {

    class ENTRY_SELECTION {
    public:
     void make_list(void);
     ENTRY_SELECTION(ENTRY_SELECTION* a0, WINDOW* a1, OBJENTRY_DATA* a2, u32 a3, FuncDef48* a4);
     void ChangeType(s32 a0, void* a1);
     void ChangePage(s32 a0, void* a1);
     void SelectCallback(EVENT a0, s32 a1, void* a2);
     s32 Compare(void* a0, void* a1);
     void Open(char* a0, s32 a1, s32 a2, OBJENTRY_DATA* a3, u32 a4, FuncDef49* a5);
     ~ENTRY_SELECTION();
    };

}  // namespace YS

#endif
