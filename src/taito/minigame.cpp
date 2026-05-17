#include "minigame.hpp"

extern "C" void func_002cf280(u32, u32, u32);

namespace Ti {



LFlag::LFlag(u32 bits) { *reinterpret_cast<u32*>(this) = bits; }

bool LFlag::check(u32 bits) { return (*reinterpret_cast<u32*>(this) & bits) != 0; }

void LFlag::reset(u32 bits) { func_002cf280((u32)this, 0, bits); }

void LFlag::zero() { *reinterpret_cast<u32*>(this) = 0; }
}  // namespace Ti
