#include "../common/types.h"


namespace YI {

} // namespace YI

class IMAGE;
class SPRITE;

class SPRITE {
public:
 SPRITE();
 ~SPRITE();
 void Reset(void);
 void SetDrawZ(u32 a0);
 void SetScale(f32 a0, f32 a1, f32 a2);
 void SetRotate(f32 a0, f32 a1, f32 a2);
 void ChangeNumber(s32 a0);
 void SetNumber(s32 a0);
 void SetNormalMode(void);
 u64 Init(void* a0, IMAGE* a1);
 void SetGroupX(s32 a0, s32 a1, s32 a2);
 void SetGroupY(s32 a0, s32 a1, s32 a2);
 s32 GetGroupW(s32 a0, s32 a1);
 void SetGroupW(s32 a0, s32 a1, s32 a2);
 s32 GetGroupH(s32 a0, s32 a1);
 void SetGroupH(s32 a0, s32 a1, s32 a2);
 void SetGroupWH(s32 a0, s32 a1, s32 a2, s32 a3);
 void Control(void);
 void Draw(void);
 void SetDirextUV(ushort* a0, ushort* a1);
 void _ChangeNumber(s32 a0);
 u64 _GetScrollMode(s32 a0);
 void _Draw(s32 a0, s32 a1, s32 a2, s32 a3);
 void _Draw2(s32 a0, s32 a1, s32 a2, s32 a3);
};
