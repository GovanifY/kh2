#include "types.h"


namespace YS {

} // namespace YS

class DRAWPACKET;

class FONT {
public:
 u64 get_tex0(s32 a0);
 u64 is_clip(s32 a0, s32 a1, s32 a2, s32 a3);
 void InitTexture(void);
 u8 get_width(s32 a0);
 u64 get_space_width(void);
 void Init(void);
 u32 GetSequence(void);
 u8 GetIconWidth(s32 a0);
 void SetImage(void* a0);
 void send_init_packet(DRAWPACKET* a0);
 u64 make_packet(DRAWPACKET* a0, s32 a1, s32 a2, u32 a3, s32 a4, f32 a5, f32 a6);
 u64 make_packet_italic(DRAWPACKET* a0, s32 a1, s32 a2, u32 a3, s32 a4, s32 a5, f32 a6, f32 a7);
 u64 make_icon_packet(DRAWPACKET* a0, s32 a1, s32 a2, u32 a3, s32 a4);
};
