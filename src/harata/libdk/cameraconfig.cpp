#include "types.h"


namespace dk {

} // namespace dk

class PAD;

class CameraConfig {
public:
 bool isZoomIn(PAD* a0);
 bool isZoomOut(PAD* a0);
 bool isLeft(PAD* a0);
 bool isRight(PAD* a0);
 u64 isManual(PAD* a0);
};
