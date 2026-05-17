#ifndef KH2_SRC_TOZAWA_HELP_GRA_HPP
#define KH2_SRC_TOZAWA_HELP_GRA_HPP

#include "types.h"

namespace Tz {

class HelpGra {
public:
    void update(void);
    void draw(void);
    u32 isExist();
    void create(void* a0, void* a1, s32 a2);
    void SetPri(s32 a0);
    HelpGra();
    ~HelpGra();
};

}  // namespace Tz

#endif
