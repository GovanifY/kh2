#ifndef KH2_SRC_TOZAWA_JM_PUZZLE_HPP
#define KH2_SRC_TOZAWA_JM_PUZZLE_HPP

#include "../common/types.h"

namespace Tz {

class JmPuzzle {
public:
    static void InitInfo();
    static u32 CalcMaxPiece(s32);
};

}  // namespace Tz

#endif
