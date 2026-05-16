#include "types.h"


namespace worldmap {

} // namespace worldmap

class CloseUpCamera;
class FVector;
class TARGET;

class CloseUpCamera {
public:
 ~CloseUpCamera();
 void start(TARGET* a0, FVector* a1, f32 a2);
 void end(void);
 void update(void);
 CloseUpCamera(CloseUpCamera* a0, TARGET* a1, FVector* a2, f32 a3);
};
