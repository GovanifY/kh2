#include "types.h"


namespace dk {

} // namespace dk

class ALLOCATOR;
class CollisionParam;
class FVector;
class Line;
class MapFile;
class ObjDrawList;
class ObjOcc;
class OnPolygonInfo;
struct TASK;
class ViewFrustum;
class uchar;

class Octree {
public:
 void buildOcclusionFrustum(void);
 void calcSpotSize(void);
 u32 getSkeltonType(CollisionParam* a0);
 void addMenuMapInfo(u64 a0, s32 a1);
 void wallClipOn(void);
 void create(MapFile* a0, ALLOCATOR* a1, bool a2, u64 a3);
 void destroy(void);
 void setSkyObject(ObjDrawList* a0, s32 a1);
 void setDrawObject(ObjDrawList* a0);
 void insertDrawObject(ObjDrawList* a0);
 void findDrawObject(ObjDrawList* a0);
 void clearObjDrawList_task(TASK* a0);
 void drawScene_task(TASK* a0);
 u32 collisionToMap(CollisionParam* a0);
 void intersectFootPrint(Line* a0, FVector* a1, s32 a2);
 u64 intersectLineMap(Line* a0, FVector* a1, ushort* a2, s32 a3);
 void intersectLineMap(Line* a0, FVector* a1, s32 a2);
 u64 intersectLine(Line* a0, FVector* a1, ushort* a2, ObjOcc** a3, s32 a4);
 void intersectLine(Line* a0, FVector* a1, s32 a2);
 bool intersectLineCamera(Line* a0, FVector* a1, ushort* a2, ObjOcc** a3);
 u64 intersectLineIk(Line* a0, FVector* a1);
 void getAttr(u16 a0, bool a1);
 void getNormal(u16 a0, bool a1);
 void getOnPolygonInfo(CollisionParam* a0, OnPolygonInfo* a1);
 void getOnPolygonInfo(FVector* a0, OnPolygonInfo* a1);
 void getPolygon(u16 a0);
 void getPlane(u16 a0);
 u32 getAttrKind(u16 a0, bool a1);
 void isExistPolygon(u16 a0);
 void createOcclusionFrustum(ViewFrustum* a0, FVector* a1);
 u64 cullingEffect(ViewFrustum* a0, FVector* a1);
 void hide(u32 a0);
 void visible(u32 a0);
 void getColorInfo(Line* a0);
 void showSky(void);
 void showMapSky(void);
 void hideSky(void);
 void hideMapSky(void);
 void start(void);
 void stop(void);
 void setTextureOrderDraw(void);
 void setZSortDraw(void);
 u64 isTextureOrderDraw(void);
 void setColor(uchar a0, uchar a1, uchar a2);
 u32 getModelObj(void);
 void setSkipAll(void);
 u64 isWallClipOn(void);
 void wallClipOff(void);
 void destroyMapCache(void);
 void drawline_map_callback(s32 a0);
 void coll_map_callback(s32 a0);
 void draw_map_callback(s32 a0);
 void group_callback(s32 a0);
 u64 isExistGroup(s32 a0);
};
