#ifndef KH2_SRC_HARATA_LIBDK_OBJENTRY_HPP
#define KH2_SRC_HARATA_LIBDK_OBJENTRY_HPP

#include "../../common/types.h"

namespace dk {

class BgObjPos;

class ObjEntry {
public:
    void setup(void* a0);
    void create(s32 a0, u64 a1);
    void show(u32 a0);
    void hide(u32 a0);
    u32 getBop(void);
    void putLodData(BgObjPos* a0);
    s32 getKindMax(void);
    void getSaveFileName(char* a0);
    void save(void);
};

}  // namespace dk

#endif
