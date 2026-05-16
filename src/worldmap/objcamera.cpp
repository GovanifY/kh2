#include "types.h"


namespace worldmap {

} // namespace worldmap

class ObjCamera;
class PAD;
class Player;

class ObjCamera {
public:
 ~ObjCamera();
 u64 update(void);
 void start(Player* a0, PAD* a1);
 u32 getCurrent(void);
 ObjCamera(ObjCamera* a0, Player* a1, PAD* a2);
};
