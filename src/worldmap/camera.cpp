#include "types.h"


namespace worldmap {

} // namespace worldmap

class Camera;

class Camera {
public:
 u64 update(void);
 void sleep(void);
 void initialize(void);
 ~Camera();
};
