#ifndef KH2_SRC_HARATA_LIBDK_FIELD_HPP
#define KH2_SRC_HARATA_LIBDK_FIELD_HPP

#include "../../common/types.h"

struct TASK;

namespace dk {

class FuncDef8;
class FuncDef9;

class Field {
public:
    void WorldMapStart(s32 a0, u32 a1);
    void TitleStart(bool a0);
    void init(void);
    void execTitle_task(TASK* a0);
};

}  // namespace dk

#endif
