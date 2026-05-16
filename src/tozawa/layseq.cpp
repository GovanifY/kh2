#include "types.h"


namespace Tz {

} // namespace Tz

class LaySeq;
class Layout;

class LaySeq {
public:
 void update(void);
 void SetSeqNum(short* a0);
 void SetLayNum(short* a0);
 void create(s32 a0, s32 a1, s32 a2, Layout* a3, short* a4, short* a5, s32 a6, s32 a7);
 ~LaySeq();
};
