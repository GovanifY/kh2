#ifndef KH2_SRC_YASUI_LIBYSDBG_WIDGET_VECTOR_HPP
#define KH2_SRC_YASUI_LIBYSDBG_WIDGET_VECTOR_HPP

#include "types.h"

namespace YS {

class FVector;

class WIDGET_VECTOR {
public:
    WIDGET_VECTOR(WIDGET_VECTOR* a0, s32 a1, s32 a2, s32 a3, FVector* a4, f32 a5, f32 a6, f32 a7, s32 a8);
    ~WIDGET_VECTOR();
};

}  // namespace YS

#endif
