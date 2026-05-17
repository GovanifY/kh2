#ifndef KH2_SRC_LIBYW_MENU_HPP
#define KH2_SRC_LIBYW_MENU_HPP

#include "types.h"

class ADVICE;
class ELEM;
class FuncDef13;
class FuncDef14;
class FuncDef74;
class FuncDef75;
class MENU;
class MemoryAllocator;
struct TASK;

class MENU {
public:
    ~MENU();
    void Init(void);
    void Ensure(void);
    void EnsureForRebirth(void);
    void Start(void);
    void StartForRebirth(void);
    void ResultStart(void);
    void ItemListStart(void);
    void End(void);
    void EndForRebirth(void);
    void ResultEnd(void);
    void ItemListEnd(void);
    void AdviceLoad(ADVICE* a0);
    void AdviceStart(void);
    void AdviceEnd(void);
    void AdviceIsReady(void);
    void ResultIsComplete(void);
    void ItemListIsActive(void);
    void DrawItemName(u32 a0, s32 a1, s32 a2, u32 a3, s32 a4);
    void DrawItemNameUnknown(u32 a0, s32 a1, s32 a2, u32 a3, s32 a4);
    void ExecTask(TASK* a0);
    void ExecTaskFinalizer(TASK* a0);
    void CreateMenuCamera(void);
    void Init(TASK* a0);
    void Ensure(void);
    void CreateMenuLayout(void);
    void CreateEditLayout(void);
    u32 GetMenuCamera(void);
    u32 GetBodySelctCamera(void);
    MENU(MENU* a0, char* a1, s32 a2, s32 a3, ELEM* a4, FuncDef74* a5);
    MENU(MENU* a0, char* a1, s32 a2, s32 a3, ELEM* a4, FuncDef75* a5);
    ~MENU();
    void select(s32 a0);
};

class Menu {
public:
    void read(void);
    void initialize(void);
    void exit(void);
    void toJiminy(s32 a0);
};

u64 isRunning(void);
void setType(s32 a0);
void SetPauseExitCallBack(FuncDef13* a0);
void Init(void);
s64 Type2LocalId(s32 a0);
u64 Type2MenuMode(s32 a0);
u64 isPauseMenu(s32 a0);
u32 getType(void);
u32 getReserveType(void);
void pauseExit(void);
void createExecTask(void);
void pauseExecTask(TASK* a0);
void CreateTask(s32 a0, s32 a1, FuncDef14* a2);
u32 GetAllocator(void);
u32 GetObjAllocator(void);
void CreateAllocator(s32 a0, MemoryAllocator* a1);
void CreateAllocator(char* a0, u32 a1);
void DestoryAllocator(void);
void SetGameMode(s32 a0);
u32 GetGameMode(void);
void SetMapJump(s32 a0);
void CreateTaskManager(void);
void Start(TASK* a0);
void MapJump(void);
void finalize(void);
void Ensure(TASK* a0);

#endif
