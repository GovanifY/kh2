#include "types.h"


namespace YS {

} // namespace YS

class ...;
class FONT;
class STYLE;

class MESSAGE {
public:
 s64 get_font(s32 a0);
 bool is_control_code(s32 a0);
 s32 get_size(void);
 u32 decode(char* a0, u32 a1, ...);
 void Set(s32 a0, void* a1);
 void SysInit(void);
 void Read(s32 a0, s32 a1);
 void Init(s32 a0, s32 a1);
 void Exit(s32 a0);
 void CodeToMessage(ushort* a0, s32 a1, char* a2);
 u16 get_short(s32 a0);
 void get_line_size(FONT* a0, STYLE* a1, u64 a2, u64 a3, u64 a4);
 void get_page_size(FONT* a0, STYLE* a1, u64 a2, u64 a3, u64 a4);
 void get_max_size(FONT* a0, STYLE* a1, u64 a2, u64 a3, u64 a4, uint* a5);
 void get_line_cnt(void);
 s32 dup(char* a0);
 s32 get_line_length(void);
};
