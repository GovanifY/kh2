#pragma once

#include "../common/types.h"

namespace Tz {

class Spl;

class Hermite {
public:
    double CalcSpline(Spl* a0, Spl* a1, f32 a2);
};

}  // namespace Tz

