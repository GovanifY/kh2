#include "./misc.hpp"

void printf(void* self) { reinterpret_cast<IntSlot*>(self)->value = 0; }

void pppPartDrawEnd() {}

void ErrorRaise(void* self) { reinterpret_cast<IntSlot*>(self)->value = 0; }
