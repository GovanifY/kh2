#include "effect_data.hpp"

namespace ryj {


struct EFFECT_DATA_Layout {
    void* value;
};

void EFFECT_DATA::set(void* v) { reinterpret_cast<EFFECT_DATA_Layout*>(this)->value = v; }
}  // namespace ryj
