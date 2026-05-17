#ifndef KH2_SRC_LIBGUMI_TEXTURE_HPP
#define KH2_SRC_LIBGUMI_TEXTURE_HPP

#include "../common/types.h"

class Vif1PacketBuffer;

namespace gm {

    class TEXTURE {
    public:
     void SendGs(Vif1PacketBuffer* a0, s32 a1);
     void ClutPurge(Vif1PacketBuffer* a0);
    };

}  // namespace gm

#endif
