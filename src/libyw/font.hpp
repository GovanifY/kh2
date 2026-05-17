#ifndef KH2_SRC_LIBYW_FONT_HPP
#define KH2_SRC_LIBYW_FONT_HPP

#include "../common/types.h"

class BINARC;
class COLOR;
class DRAWPACKET;

class FONT {
public:
    s32 GetTextHeight(char* a0);
    s32 GetTextWidth(char* a0);
    void Send(u32 a0);
    void Print(s32 a0, s32 a1, COLOR* a2, char* a3);
    void Init(BINARC* a0);
    u32 Get(s32 a0);
    void GetCr(s32 a0);
    u64 get_tex0(s32 a0);
    u64 is_clip(s32 a0, s32 a1, s32 a2, s32 a3);
    void InitTexture();
    u8 get_width(s32 a0);
    u64 get_space_width();
    void Init();
    u32 GetSequence();
    u8 GetIconWidth(s32 a0);
    void SetImage(void* a0);
    void send_init_packet(DRAWPACKET* a0);
    u64 make_packet(DRAWPACKET* a0, s32 a1, s32 a2, u32 a3, s32 a4, f32 a5, f32 a6);
    u64 make_packet_italic(DRAWPACKET* a0, s32 a1, s32 a2, u32 a3, s32 a4, s32 a5, f32 a6, f32 a7);
    u64 make_icon_packet(DRAWPACKET* a0, s32 a1, s32 a2, u32 a3, s32 a4);
};

#endif
