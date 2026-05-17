#pragma once

#include "../common/types.h"

struct IntSlot {
    s32 value;
};

void printf(void* self);
void pppPartDrawEnd();
void ErrorRaise(void* self);
