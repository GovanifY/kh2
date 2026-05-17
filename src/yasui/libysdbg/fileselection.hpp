#ifndef KH2_SRC_YASUI_LIBYSDBG_FILESELECTION_HPP
#define KH2_SRC_YASUI_LIBYSDBG_FILESELECTION_HPP

#include "../../common/types.h"

class FILESELECTION;
class FuncDef50;

namespace YS {

    class FILESELECTION {
    public:
     void set_list(void);
     FILESELECTION(FILESELECTION* a0, s32 a1, s32 a2, s32 a3, char* a4, FuncDef50* a5);
     ~FILESELECTION();
    };

}  // namespace YS

#endif
