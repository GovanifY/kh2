#ifndef KH2_SRC_TOZAWA_HERMITE_HPP
#define KH2_SRC_TOZAWA_HERMITE_HPP

#include "types.h"

namespace Tz {

class Spl;

class Hermite {
public:
    double CalcSpline(Spl* a0, Spl* a1, f32 a2);
};

}  // namespace Tz

#endif
