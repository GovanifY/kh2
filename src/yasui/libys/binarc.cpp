#include "types.h"


namespace YS {

} // namespace YS


class BINARC {
public:
 void setup(void);
 void shutdown(s32 a0);
 void preSetup(void);
 void afterMove(void);
 void beforeMove(void);
 s32 get_file_num(u32 a0);
 void get_file_num(uint* a0, u32 a1, u32 a2);
 s32 get_info(u32 a0, s32 a1);
 s32 get_info_by_tag(u32 a0, u32 a1, s32 a2);
};
