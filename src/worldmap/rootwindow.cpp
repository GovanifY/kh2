#include "types.h"


namespace worldmap {

} // namespace worldmap

class RootWindow;
struct TASK;

class RootWindow {
public:
 u32 get(void);
 RootWindow();
 ~RootWindow();
 void execTask(TASK* a0);
};
