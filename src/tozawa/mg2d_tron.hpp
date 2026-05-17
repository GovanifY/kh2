#ifndef KH2_SRC_TOZAWA_MG2D_TRON_HPP
#define KH2_SRC_TOZAWA_MG2D_TRON_HPP

#include "types.h"

namespace Tz {

class Mg2DTron {
public:
    Mg2DTron();
    void Leave(s32);
    ~Mg2DTron();
    void CreateSeq(s32, s32);
};

}  // namespace Tz

#endif
