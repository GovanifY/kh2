#include "types.h"

// Namespace inferred from existing PS2 symbol/file clusters.

namespace YS {

} // namespace YS

class Aabbox;
class CollisionParam;
class FMatrix;
class FVector;
class MODEL;
struct TASK;

class MODEL {
public:
 MODEL(MODEL* a0, s32 a1, FVector* a2, s32 a3, ushort* a4, bool a5);
 void ExecTask(TASK* a0);
 void InitField(void);
 void Draw(MODEL* a0, FMatrix* a1, u32 a2, s32 a3);
 void DrawCube(FMatrix* a0, u32 a1, s32 a2);
 void DrawSphere(FMatrix* a0, u32 a1, s32 a2);
 void DrawColumn(FMatrix* a0, u32 a1, s32 a2);
 void DrawBgCollision(CollisionParam* a0, u32 a1, s32 a2);
 void DrawBBox(Aabbox* a0, u32 a1, s32 a2);
};
