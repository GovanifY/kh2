#ifndef KH2_SRC_YASUI_LIBYS_HITMARK_HPP
#define KH2_SRC_YASUI_LIBYS_HITMARK_HPP

#include "../../common/types.h"

class EFFECT;

namespace YS {

    class HITMARK {
    public:
     void Init(void);
     void Exec(void);
     void Add(EFFECT* a0);
    };

}  // namespace YS

#endif
