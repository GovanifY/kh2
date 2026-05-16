#include "types.h"


namespace dk {

} // namespace dk

class GAUGE_PLAYER;
class IMAGE;
class OBJ;
struct TASK;

class GAUGE_PLAYER {
public:
 u64 getDriveTimeStatus(int* a0, int* a1);
 u64 getDriveCounter(void);
 u32 getDriveCounterSqNum(void);
 void createDriveCircle(s32 a0);
 void createDriveTimeCircle(s32 a0, s32 a1);
 void checkDispDrive(void);
 void updateDrive(void);
 u64 getDriveMeterSqNum(void);
 u64 getDriveLoopSqNum(void);
 void returnNormal(void);
 void setSummonFace(s32 a0, s32 a1);
 void summonStart(void);
 u64 getDriveInSqNum(void);
 void updateMP(void);
 void createBar(s32 a0, s32 a1);
 void createCircle(s32 a0, s32 a1);
 void checkHPold(void);
 void skip(void);
 void setFace(void);
 void update(void);
 void setCure(void);
 void reload(void);
 void setDamage(s32 a0);
 void damageSmall(void);
 void damageMiddle(void);
 void damageLarge(void);
 void cure(void);
 void createHP(uchar* a0, IMAGE* a1, s32 a2, s32 a3);
 void createMP(uchar* a0, IMAGE* a1, s32 a2, s32 a3);
 void createDrive(uchar* a0, IMAGE* a1, s32 a2, s32 a3);
 void checkSummonFaceTask(TASK* a0);
 void create(OBJ* a0);
 void checkAlertOff(void);
 ~GAUGE_PLAYER();
};
