#ifndef KH2_SRC_YASUI_LIBYSDBG_TEST_CAMERA_HPP
#define KH2_SRC_YASUI_LIBYSDBG_TEST_CAMERA_HPP

#include "../../common/types.h"

class OBJ;
struct TASK;

namespace YS {

    class TEST_CAMERA {
    public:
     void ExecTask(TASK* a0);
     void Start(OBJ* a0);
     void Stop(void);
    };

}  // namespace YS

#endif
