#include "types.h"


namespace YS {

} // namespace YS

class EFFECT;

class EFFECT {
public:
 void Read(void);
 void Init(void);
 void Ensure(void);
 void Exec(void);
 void AddDeadEffect(EFFECT* a0);
};
