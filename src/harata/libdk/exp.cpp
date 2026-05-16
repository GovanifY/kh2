#include "types.h"


namespace dk {

} // namespace dk

class Exp;
class FVector;
class IMAGE;

class Exp {
public:
 s32 getSeqNumber(int* a0, s32 a1, int* a2);
 void create(s32 a0, IMAGE* a1, s32 a2);
 void destroy(void);
 void update(void);
 void draw(void);
 void print(FVector* a0, s32 a1, s32 a2);
 void init(void);
 void exit(void);
 void on(void);
 void off(void);
 ~Exp();
};
