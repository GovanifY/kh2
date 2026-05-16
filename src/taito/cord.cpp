#include "types.h"


namespace Ti {

} // namespace Ti

class Cord;

class Cord {
public:
 Cord();
 ~Cord();
 void init(void);
 void step(f32 a0, s32 a1);
 void add_vertical_force(f32 a0, f32 a1);
 double get_vertical_pos(f32 a0);
 double get_length(void);
};
