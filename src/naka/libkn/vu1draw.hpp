#ifndef KH2_SRC_NAKA_LIBKN_VU1DRAW_HPP
#define KH2_SRC_NAKA_LIBKN_VU1DRAW_HPP

#include "../../common/types.h"

class ALLOCATOR;
class CODE_TYPE;
class DRAW_QUEUE_TYPE;
class DrawParam;
class DrawQueue;
class ModelObj;
class ObjDrawList;
class PHASE;
class ProjectionCamera;
class SHADOW_SIZE;
class SendImagePacket;
class Vif1PacketBuffer;
class uchar;

namespace kn {

    class VU1Draw {
    public:
     u32 getPhase(void);
     void getFogColor(uchar* a0, uchar* a1, uchar* a2);
     u64 getGsALPHA(PHASE a0, s32 a1, uchar a2);
     u64 getGsTEST(PHASE a0, s32 a1, uchar a2);
     void flush_Regular(DrawQueue* a0);
     void flush_Alpha(DrawQueue* a0);
     void flush_Shadow(void);
     void setFogLimiter(f32 a0, f32 a1);
     void setFogRange(f32 a0, f32 a1);
     void setFogColor(uchar a0, uchar a1, uchar a2);
     void resetTexture(void);
     void resetMicrocode(void);
     void init(void);
     void allocBuffer(ALLOCATOR* a0, u32 a1, u32 a2);
     void freeBuffer(ALLOCATOR* a0);
     void entryMicrocode(Vif1PacketBuffer* a0, CODE_TYPE a1);
     u64 checkVRAM(SendImagePacket* a0, void* a1);
     void accumPurge(void);
     bool entryImage(Vif1PacketBuffer* a0, SendImagePacket* a1);
     void makeSendImagePacket(SendImagePacket* a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, void* a8);
     void linkDrawQueue(DRAW_QUEUE_TYPE a0, DrawQueue* a1);
     void drawShadow(ModelObj* a0, ProjectionCamera* a1, DrawParam* a2, short* a3, ProjectionCamera* a4, ProjectionCamera* a5, ObjDrawList** a6, SHADOW_SIZE a7);
     void unlinkModel(ModelObj* a0);
     void close(void);
     u64 kick(bool a0);
     void wait(void);
     void flush(void);
     void shadowEnv(SHADOW_SIZE a0);
     void shadowTextureSoft(SHADOW_SIZE a0);
     void frameBuffer2Texture(void);
     u32 setPhase(PHASE a0);
    };

}  // namespace kn

#endif
