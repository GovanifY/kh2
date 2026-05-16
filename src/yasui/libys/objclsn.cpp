#include "types.h"


namespace YS {

} // namespace YS

class Aabbox;
class COLLISION;

class OBJCLSN {
public:
 void free(void);
 void set(void);
 void calc_bounding_box(Aabbox* a0);
 void make_space(COLLISION* a0);
 void draw(u32 a0);
};
