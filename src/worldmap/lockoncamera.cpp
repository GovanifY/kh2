#include "types.h"


namespace worldmap {

} // namespace worldmap

class FVector;
class LockOnCamera;
class PLAYER;
class TARGET;

class LockOnCamera {
public:
 ~LockOnCamera();
 bool update(void);
 void start(PLAYER* a0, TARGET* a1);
 void end(void);
 LockOnCamera(LockOnCamera* a0, PLAYER* a1, TARGET* a2);
 void getEyeAt(FVector* a0, FVector* a1);
};
