#include "./saveram.hpp"

namespace SAVERAM {
s32 GetGameLevel(void* self) { return reinterpret_cast<Layout*>(self)->gameLevel; }
}  // namespace SAVERAM
