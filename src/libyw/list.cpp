#include "types.h"


class COLOR;
class EVENT;
class FuncDef26;
class LIST;
class RECT;
class iterator;
class list;

class LIST {
public:
 LIST(LIST* a0, s32 a1, s32 a2, char** a3, FuncDef26* a4, void* a5);
 void idle_func(void);
 void focus_func(EVENT a0, s32 a1, s32 a2);
 void draw_func(RECT* a0, COLOR* a1);
 ~LIST();
};

class list<> {
public:
 void _Incsize(u32 a0);
 void _Splice(iterator a0, list* a1, iterator a2, iterator a3, u32 a4);
 void sort(void);
};
