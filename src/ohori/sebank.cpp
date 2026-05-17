#include "sebank.hpp"

void SE_BANK::setGumiMode() {
    *(u32*)((u32)this + (s32)(324)) = 1u;
    *(u8*)((u32)this + (s32)(336)) = (u8)0u;
}
