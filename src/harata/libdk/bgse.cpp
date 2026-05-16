#include "types.h"

extern void YS_CACHE_BUFF_FixFree(void*) asm("_ZN2YS10CACHE_BUFF7FixFreeEPv");

namespace dk {

class BGSE {
public:
    static void clearOff();
    static void free(void*);
};

extern u8 D_00347d28 asm("D_00347d28");
void BGSE::clearOff() { D_00347d28 = (u8)0; }

void BGSE::free(void* p) { YS_CACHE_BUFF_FixFree(p); }

}  // namespace dk
