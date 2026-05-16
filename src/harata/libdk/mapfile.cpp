#include "types.h"


namespace dk {

} // namespace dk

class AREA;
class MapFile;

class MapFile {
public:
 MapFile();
 u32 getMapModelAddress(void);
 u32 getMapTexAddress(void);
 u32 getOcdAddress(void);
 u32 getOccAddress(void);
 u32 getOchAddress(void);
 u32 getOclAddress(void);
 u32 getOwaAddress(void);
 u32 getMonAddress(void);
 u32 getBopAddress(void);
 u32 getPlxAddress(void);
 u32 getTelopImdAddress(void);
 u32 getTelopSqdAddress(void);
 u32 getPaxAddress(void);
 u32 getRadarAddress(s32 a0);
 u32 getMclAddress(void);
 s32 getBgObjModelAddress(s32 a0);
 u32 getBgObjTexAddress(s32 a0);
 u32 getBgObjMotionSetAddress(s32 a0);
 void buildMapFileName(AREA* a0, char* a1);
 void setMapFile(void);
 void readRequest(void);
 void init(void);
 void exit(void);
};
