#include "../../common/types.h"


namespace YS {

} // namespace YS

struct TASK;

class PAD {
public:
 void make_trigger(u64 a0);
 void clear(u64 a0);
 void ReadTask(TASK* a0);
 void Init(void);
};
