.set noreorder
.text

.section .text.func_002f20c0, "ax", @progbits
.globl _GetGsDxDyOffset
.type _GetGsDxDyOffset, @function
.globl func_002f20c0
.type func_002f20c0, @function
.ent func_002f20c0
func_002f20c0:
_GetGsDxDyOffset:
    addiu $3, $0, 128
    syscall
    jr $31
     nop
.end func_002f20c0

.section .text.func_00305220, "ax", @progbits
.globl SetGsCrt
.type SetGsCrt, @function
.globl func_00305220
.type func_00305220, @function
.ent func_00305220
func_00305220:
SetGsCrt:
    addiu $3, $0, 2
    syscall
    jr $31
     nop
.end func_00305220

.section .text.func_00305240, "ax", @progbits
.globl _Exit
.type _Exit, @function
.globl func_00305240
.type func_00305240, @function
.ent func_00305240
func_00305240:
_Exit:
    addiu $3, $0, 4
    syscall
    jr $31
     nop
.end func_00305240

.section .text.func_00305260, "ax", @progbits
.globl _LoadExecPS2
.type _LoadExecPS2, @function
.globl func_00305260
.type func_00305260, @function
.ent func_00305260
func_00305260:
_LoadExecPS2:
    addiu $3, $0, 6
    syscall
    jr $31
     nop
.end func_00305260

.section .text.func_003052d0, "ax", @progbits
.globl SetVTLBRefillHandler
.type SetVTLBRefillHandler, @function
.globl func_003052d0
.type func_003052d0, @function
.ent func_003052d0
func_003052d0:
SetVTLBRefillHandler:
    addiu $3, $0, 13
    syscall
    jr $31
     nop
.end func_003052d0

.section .text.func_00305300, "ax", @progbits
.globl AddIntcHandler
.type AddIntcHandler, @function
.globl func_00305300
.type func_00305300, @function
.ent func_00305300
func_00305300:
AddIntcHandler:
    addiu $3, $0, 16
    syscall
    jr $31
     nop
.end func_00305300

.section .text.func_00305310, "ax", @progbits
.globl AddIntcHandler2
.type AddIntcHandler2, @function
.globl func_00305310
.type func_00305310, @function
.ent func_00305310
func_00305310:
AddIntcHandler2:
    addiu $3, $0, 16
    syscall
    jr $31
     nop
.end func_00305310

.section .text.func_00305320, "ax", @progbits
.globl RemoveIntcHandler
.type RemoveIntcHandler, @function
.globl func_00305320
.type func_00305320, @function
.ent func_00305320
func_00305320:
RemoveIntcHandler:
    addiu $3, $0, 17
    syscall
    jr $31
     nop
.end func_00305320

.section .text.func_00305330, "ax", @progbits
.globl AddDmacHandler
.type AddDmacHandler, @function
.globl func_00305330
.type func_00305330, @function
.ent func_00305330
func_00305330:
AddDmacHandler:
    addiu $3, $0, 18
    syscall
    jr $31
     nop
.end func_00305330

.section .text.func_00305350, "ax", @progbits
.globl RemoveDmacHandler
.type RemoveDmacHandler, @function
.globl func_00305350
.type func_00305350, @function
.ent func_00305350
func_00305350:
RemoveDmacHandler:
    addiu $3, $0, 19
    syscall
    jr $31
     nop
.end func_00305350

.section .text.func_00305360, "ax", @progbits
.globl _EnableIntc
.type _EnableIntc, @function
.globl func_00305360
.type func_00305360, @function
.ent func_00305360
func_00305360:
_EnableIntc:
    addiu $3, $0, 20
    syscall
    jr $31
     nop
.end func_00305360

.section .text.func_00305370, "ax", @progbits
.globl _DisableIntc
.type _DisableIntc, @function
.globl func_00305370
.type func_00305370, @function
.ent func_00305370
func_00305370:
_DisableIntc:
    addiu $3, $0, 21
    syscall
    jr $31
     nop
.end func_00305370

.section .text.func_00305380, "ax", @progbits
.globl _EnableDmac
.type _EnableDmac, @function
.globl func_00305380
.type func_00305380, @function
.ent func_00305380
func_00305380:
_EnableDmac:
    addiu $3, $0, 22
    syscall
    jr $31
     nop
.end func_00305380

.section .text.func_00305390, "ax", @progbits
.globl _DisableDmac
.type _DisableDmac, @function
.globl func_00305390
.type func_00305390, @function
.ent func_00305390
func_00305390:
_DisableDmac:
    addiu $3, $0, 23
    syscall
    jr $31
     nop
.end func_00305390

.section .text.func_003053c0, "ax", @progbits
.globl _iEnableIntc
.type _iEnableIntc, @function
.globl func_003053c0
.type func_003053c0, @function
.ent func_003053c0
func_003053c0:
_iEnableIntc:
    addiu $3, $0, -26
    syscall
    jr $31
     nop
.end func_003053c0

.section .text.func_003053d0, "ax", @progbits
.globl _iDisableIntc
.type _iDisableIntc, @function
.globl func_003053d0
.type func_003053d0, @function
.ent func_003053d0
func_003053d0:
_iDisableIntc:
    addiu $3, $0, -27
    syscall
    jr $31
     nop
.end func_003053d0

.section .text.func_003053e0, "ax", @progbits
.globl _iEnableDmac
.type _iEnableDmac, @function
.globl func_003053e0
.type func_003053e0, @function
.ent func_003053e0
func_003053e0:
_iEnableDmac:
    addiu $3, $0, -28
    syscall
    jr $31
     nop
.end func_003053e0

.section .text.func_003053f0, "ax", @progbits
.globl _iDisableDmac
.type _iDisableDmac, @function
.globl func_003053f0
.type func_003053f0, @function
.ent func_003053f0
func_003053f0:
_iDisableDmac:
    addiu $3, $0, -29
    syscall
    jr $31
     nop
.end func_003053f0

.section .text.func_00305420, "ax", @progbits
.globl CreateThread
.type CreateThread, @function
.globl func_00305420
.type func_00305420, @function
.ent func_00305420
func_00305420:
CreateThread:
    addiu $3, $0, 32
    syscall
    jr $31
     nop
.end func_00305420

.section .text.func_00305440, "ax", @progbits
.globl _StartThread
.type _StartThread, @function
.globl func_00305440
.type func_00305440, @function
.ent func_00305440
func_00305440:
_StartThread:
    addiu $3, $0, 34
    syscall
    jr $31
     nop
.end func_00305440

.section .text.func_00305460, "ax", @progbits
.globl ExitDeleteThread
.type ExitDeleteThread, @function
.globl func_00305460
.type func_00305460, @function
.ent func_00305460
func_00305460:
ExitDeleteThread:
    addiu $3, $0, 36
    syscall
    jr $31
     nop
.end func_00305460

.section .text.func_003054b0, "ax", @progbits
.globl ChangeThreadPriority
.type ChangeThreadPriority, @function
.globl func_003054b0
.type func_003054b0, @function
.ent func_003054b0
func_003054b0:
ChangeThreadPriority:
    addiu $3, $0, 41
    syscall
    jr $31
     nop
.end func_003054b0

.section .text.func_003054d0, "ax", @progbits
.globl RotateThreadReadyQueue
.type RotateThreadReadyQueue, @function
.globl func_003054d0
.type func_003054d0, @function
.ent func_003054d0
func_003054d0:
RotateThreadReadyQueue:
    addiu $3, $0, 43
    syscall
    jr $31
     nop
.end func_003054d0

.section .text.func_00305510, "ax", @progbits
.globl GetThreadId
.type GetThreadId, @function
.globl func_00305510
.type func_00305510, @function
.ent func_00305510
func_00305510:
GetThreadId:
    addiu $3, $0, 47
    syscall
    jr $31
     nop
.end func_00305510

.section .text.func_00305520, "ax", @progbits
.globl ReferThreadStatus
.type ReferThreadStatus, @function
.globl func_00305520
.type func_00305520, @function
.ent func_00305520
func_00305520:
ReferThreadStatus:
    addiu $3, $0, 48
    syscall
    jr $31
     nop
.end func_00305520

.section .text.func_00305540, "ax", @progbits
.globl SleepThread
.type SleepThread, @function
.globl func_00305540
.type func_00305540, @function
.ent func_00305540
func_00305540:
SleepThread:
    addiu $3, $0, 50
    syscall
    jr $31
     nop
.end func_00305540

.section .text.func_00305550, "ax", @progbits
.globl WakeupThread
.type WakeupThread, @function
.globl func_00305550
.type func_00305550, @function
.ent func_00305550
func_00305550:
WakeupThread:
    addiu $3, $0, 51
    syscall
    jr $31
     nop
.end func_00305550

.section .text.func_00305560, "ax", @progbits
.globl _iWakeupThread
.type _iWakeupThread, @function
.globl func_00305560
.type func_00305560, @function
.ent func_00305560
func_00305560:
_iWakeupThread:
    addiu $3, $0, -52
    syscall
    jr $31
     nop
.end func_00305560

.section .text.func_00305590, "ax", @progbits
.globl SuspendThread
.type SuspendThread, @function
.globl func_00305590
.type func_00305590, @function
.ent func_00305590
func_00305590:
SuspendThread:
    addiu $3, $0, 55
    syscall
    jr $31
     nop
.end func_00305590

.section .text.func_003055a0, "ax", @progbits
.globl _iSuspendThread
.type _iSuspendThread, @function
.globl func_003055a0
.type func_003055a0, @function
.ent func_003055a0
func_003055a0:
_iSuspendThread:
    addiu $3, $0, -56
    syscall
    jr $31
     nop
.end func_003055a0

.section .text.func_00305600, "ax", @progbits
.globl EndOfHeap
.type EndOfHeap, @function
.globl func_00305600
.type func_00305600, @function
.ent func_00305600
func_00305600:
EndOfHeap:
    addiu $3, $0, 62
    syscall
    jr $31
     nop
.end func_00305600

.section .text.func_00305620, "ax", @progbits
.globl CreateSema
.type CreateSema, @function
.globl func_00305620
.type func_00305620, @function
.ent func_00305620
func_00305620:
CreateSema:
    addiu $3, $0, 64
    syscall
    jr $31
     nop
.end func_00305620

.section .text.func_00305630, "ax", @progbits
.globl DeleteSema
.type DeleteSema, @function
.globl func_00305630
.type func_00305630, @function
.ent func_00305630
func_00305630:
DeleteSema:
    addiu $3, $0, 65
    syscall
    jr $31
     nop
.end func_00305630

.section .text.func_00305640, "ax", @progbits
.globl SignalSema
.type SignalSema, @function
.globl func_00305640
.type func_00305640, @function
.ent func_00305640
func_00305640:
SignalSema:
    addiu $3, $0, 66
    syscall
    jr $31
     nop
.end func_00305640

.section .text.func_00305650, "ax", @progbits
.globl iSignalSema
.type iSignalSema, @function
.globl func_00305650
.type func_00305650, @function
.ent func_00305650
func_00305650:
iSignalSema:
    addiu $3, $0, -67
    syscall
    jr $31
     nop
.end func_00305650

.section .text.func_00305660, "ax", @progbits
.globl WaitSema
.type WaitSema, @function
.globl func_00305660
.type func_00305660, @function
.ent func_00305660
func_00305660:
WaitSema:
    addiu $3, $0, 68
    syscall
    jr $31
     nop
.end func_00305660

.section .text.func_00305670, "ax", @progbits
.globl PollSema
.type PollSema, @function
.globl func_00305670
.type func_00305670, @function
.ent func_00305670
func_00305670:
PollSema:
    addiu $3, $0, 69
    syscall
    jr $31
     nop
.end func_00305670

.section .text.func_00305690, "ax", @progbits
.globl ReferSemaStatus
.type ReferSemaStatus, @function
.globl func_00305690
.type func_00305690, @function
.ent func_00305690
func_00305690:
ReferSemaStatus:
    addiu $3, $0, 71
    syscall
    jr $31
     nop
.end func_00305690

.section .text.func_003056a0, "ax", @progbits
.globl iReferSemaStatus
.type iReferSemaStatus, @function
.globl func_003056a0
.type func_003056a0, @function
.ent func_003056a0
func_003056a0:
iReferSemaStatus:
    addiu $3, $0, -72
    syscall
    jr $31
     nop
.end func_003056a0

.section .text.func_003056c0, "ax", @progbits
.globl SetOsdConfigParam
.type SetOsdConfigParam, @function
.globl func_003056c0
.type func_003056c0, @function
.ent func_003056c0
func_003056c0:
SetOsdConfigParam:
    addiu $3, $0, 74
    syscall
    jr $31
     nop
.end func_003056c0

.section .text.func_003056d0, "ax", @progbits
.globl GetOsdConfigParam
.type GetOsdConfigParam, @function
.globl func_003056d0
.type func_003056d0, @function
.ent func_003056d0
func_003056d0:
GetOsdConfigParam:
    addiu $3, $0, 75
    syscall
    jr $31
     nop
.end func_003056d0

.section .text.func_003058a0, "ax", @progbits
.globl FlushCache
.type FlushCache, @function
.globl func_003058a0
.type func_003058a0, @function
.ent func_003058a0
func_003058a0:
FlushCache:
    addiu $3, $0, 100
    syscall
    jr $31
     nop
.end func_003058a0

.section .text.func_003058d0, "ax", @progbits
.globl iFlushCache
.type iFlushCache, @function
.globl func_003058d0
.type func_003058d0, @function
.ent func_003058d0
func_003058d0:
iFlushCache:
    addiu $3, $0, -104
    syscall
    jr $31
     nop
.end func_003058d0

.section .text.func_003058f0, "ax", @progbits
.globl sceSifStopDma
.type sceSifStopDma, @function
.globl func_003058f0
.type func_003058f0, @function
.ent func_003058f0
func_003058f0:
sceSifStopDma:
    addiu $3, $0, 107
    syscall
    jr $31
     nop
.end func_003058f0

.section .text.func_00305940, "ax", @progbits
.globl GsGetIMR
.type GsGetIMR, @function
.globl func_00305940
.type func_00305940, @function
.ent func_00305940
func_00305940:
GsGetIMR:
    addiu $3, $0, 112
    syscall
    jr $31
     nop
.end func_00305940

.section .text.func_00305960, "ax", @progbits
.globl GsPutIMR
.type GsPutIMR, @function
.globl func_00305960
.type func_00305960, @function
.ent func_00305960
func_00305960:
GsPutIMR:
    addiu $3, $0, 113
    syscall
    jr $31
     nop
.end func_00305960

.section .text.func_00305990, "ax", @progbits
.globl SetVSyncFlag
.type SetVSyncFlag, @function
.globl func_00305990
.type func_00305990, @function
.ent func_00305990
func_00305990:
SetVSyncFlag:
    addiu $3, $0, 115
    syscall
    jr $31
     nop
.end func_00305990

.section .text.func_003059c0, "ax", @progbits
.globl sceSifDmaStat
.type sceSifDmaStat, @function
.globl func_003059c0
.type func_003059c0, @function
.ent func_003059c0
func_003059c0:
sceSifDmaStat:
    addiu $3, $0, 118
    syscall
    jr $31
     nop
.end func_003059c0

.section .text.func_003059e0, "ax", @progbits
.globl sceSifSetDma
.type sceSifSetDma, @function
.globl func_003059e0
.type func_003059e0, @function
.ent func_003059e0
func_003059e0:
sceSifSetDma:
    addiu $3, $0, 119
    syscall
    jr $31
     nop
.end func_003059e0

.section .text.func_003059f0, "ax", @progbits
.globl isceSifSetDma
.type isceSifSetDma, @function
.globl func_003059f0
.type func_003059f0, @function
.ent func_003059f0
func_003059f0:
isceSifSetDma:
    addiu $3, $0, -119
    syscall
    jr $31
     nop
.end func_003059f0

.section .text.func_00305a00, "ax", @progbits
.globl sceSifSetDChain
.type sceSifSetDChain, @function
.globl func_00305a00
.type func_00305a00, @function
.ent func_00305a00
func_00305a00:
sceSifSetDChain:
    addiu $3, $0, 120
    syscall
    jr $31
     nop
.end func_00305a00

.section .text.func_00305a10, "ax", @progbits
.globl isceSifSetDChain
.type isceSifSetDChain, @function
.globl func_00305a10
.type func_00305a10, @function
.ent func_00305a10
func_00305a10:
isceSifSetDChain:
    addiu $3, $0, -120
    syscall
    jr $31
     nop
.end func_00305a10

.section .text.func_00305a20, "ax", @progbits
.globl sceSifSetReg
.type sceSifSetReg, @function
.globl func_00305a20
.type func_00305a20, @function
.ent func_00305a20
func_00305a20:
sceSifSetReg:
    addiu $3, $0, 121
    syscall
    jr $31
     nop
.end func_00305a20

.section .text.func_00305a30, "ax", @progbits
.globl sceSifGetReg
.type sceSifGetReg, @function
.globl func_00305a30
.type func_00305a30, @function
.ent func_00305a30
func_00305a30:
sceSifGetReg:
    addiu $3, $0, 122
    syscall
    jr $31
     nop
.end func_00305a30

.section .text.func_00305a40, "ax", @progbits
.globl _ExecOSD
.type _ExecOSD, @function
.globl func_00305a40
.type func_00305a40, @function
.ent func_00305a40
func_00305a40:
_ExecOSD:
    addiu $3, $0, 123
    syscall
    jr $31
     nop
.end func_00305a40

.section .text.func_00305a50, "ax", @progbits
.globl Deci2Call
.type Deci2Call, @function
.globl func_00305a50
.type func_00305a50, @function
.ent func_00305a50
func_00305a50:
Deci2Call:
    addiu $3, $0, 124
    syscall
    jr $31
     nop
.end func_00305a50

.section .text.func_00305a80, "ax", @progbits
.globl GetMemorySize
.type GetMemorySize, @function
.globl func_00305a80
.type func_00305a80, @function
.ent func_00305a80
func_00305a80:
GetMemorySize:
    addiu $3, $0, 127
    syscall
    jr $31
     nop
.end func_00305a80

.section .text.func_00305a90, "ax", @progbits
.globl _InitTLB
.type _InitTLB, @function
.globl func_00305a90
.type func_00305a90, @function
.ent func_00305a90
func_00305a90:
_InitTLB:
    addiu $3, $0, 130
    syscall
    jr $31
     nop
.end func_00305a90

.section .text.func_0030ee88, "ax", @progbits
.globl Copy
.type Copy, @function
.globl func_0030ee88
.type func_0030ee88, @function
.ent func_0030ee88
func_0030ee88:
Copy:
    addiu $3, $0, 90
    syscall
    jr $31
     nop
.end func_0030ee88

.section .text.func_0030ef10, "ax", @progbits
.globl FindAddress
.type FindAddress, @function
.globl func_0030ef10
.type func_0030ef10, @function
.ent func_0030ef10
func_0030ef10:
FindAddress:
    addiu $3, $0, 131
    syscall
    jr $31
     nop
.end func_0030ef10

.section .text.func_0030f058, "ax", @progbits
.globl SetSyscall
.type SetSyscall, @function
.globl func_0030f058
.type func_0030f058, @function
.ent func_0030f058
func_0030f058:
SetSyscall:
    addiu $3, $0, 116
    syscall
    jr $31
     nop
.end func_0030f058

.section .text.func_0030f0c0, "ax", @progbits
.globl SetSyscall_0030f0c0
.type SetSyscall_0030f0c0, @function
.globl func_0030f0c0
.type func_0030f0c0, @function
.ent func_0030f0c0
func_0030f0c0:
SetSyscall_0030f0c0:
    addiu $3, $0, 116
    syscall
    jr $31
     nop
.end func_0030f0c0

.section .text.func_0030f0d0, "ax", @progbits
.globl Copy_0030f0d0
.type Copy_0030f0d0, @function
.globl func_0030f0d0
.type func_0030f0d0, @function
.ent func_0030f0d0
func_0030f0d0:
Copy_0030f0d0:
    addiu $3, $0, 90
    syscall
    jr $31
     nop
.end func_0030f0d0

.section .text.func_0030f118, "ax", @progbits
.globl GetEntryAddress
.type GetEntryAddress, @function
.globl func_0030f118
.type func_0030f118, @function
.ent func_0030f118
func_0030f118:
GetEntryAddress:
    addiu $3, $0, 91
    syscall
    jr $31
     nop
.end func_0030f118

.section .text.func_0030f240, "ax", @progbits
.globl Copy_0030f240
.type Copy_0030f240, @function
.globl func_0030f240
.type func_0030f240, @function
.ent func_0030f240
func_0030f240:
Copy_0030f240:
    addiu $3, $0, 90
    syscall
    jr $31
     nop
.end func_0030f240

.section .text.func_0030f280, "ax", @progbits
.globl SetSyscall_0030f280
.type SetSyscall_0030f280, @function
.globl func_0030f280
.type func_0030f280, @function
.ent func_0030f280
func_0030f280:
SetSyscall_0030f280:
    addiu $3, $0, 116
    syscall
    jr $31
     nop
.end func_0030f280

.section .text.func_0030f4e0, "ax", @progbits
.globl SetSyscall_0030f4e0
.type SetSyscall_0030f4e0, @function
.globl func_0030f4e0
.type func_0030f4e0, @function
.ent func_0030f4e0
func_0030f4e0:
SetSyscall_0030f4e0:
    addiu $3, $0, 116
    syscall
    jr $31
     nop
.end func_0030f4e0

.section .text.func_0030f4f0, "ax", @progbits
.globl Copy_0030f4f0
.type Copy_0030f4f0, @function
.globl func_0030f4f0
.type func_0030f4f0, @function
.ent func_0030f4f0
func_0030f4f0:
Copy_0030f4f0:
    addiu $3, $0, 90
    syscall
    jr $31
     nop
.end func_0030f4f0

.section .text.func_0030f538, "ax", @progbits
.globl GetEntryAddress_0030f538
.type GetEntryAddress_0030f538, @function
.globl func_0030f538
.type func_0030f538, @function
.ent func_0030f538
func_0030f538:
GetEntryAddress_0030f538:
    addiu $3, $0, 91
    syscall
    jr $31
     nop
.end func_0030f538

.section .text.func_00311300, "ax", @progbits
.globl Copy_00311300
.type Copy_00311300, @function
.globl func_00311300
.type func_00311300, @function
.ent func_00311300
func_00311300:
Copy_00311300:
    addiu $3, $0, 90
    syscall
    jr $31
     nop
.end func_00311300

.section .text.func_00311348, "ax", @progbits
.globl GetEntryAddress_00311348
.type GetEntryAddress_00311348, @function
.globl func_00311348
.type func_00311348, @function
.ent func_00311348
func_00311348:
GetEntryAddress_00311348:
    addiu $3, $0, 91
    syscall
    jr $31
     nop
.end func_00311348

.section .text.func_00311358, "ax", @progbits
.globl SetSyscall_00311358
.type SetSyscall_00311358, @function
.globl func_00311358
.type func_00311358, @function
.ent func_00311358
func_00311358:
SetSyscall_00311358:
    addiu $3, $0, 116
    syscall
    jr $31
     nop
.end func_00311358

.section .text.func_00311450, "ax", @progbits
.globl _SetTLBEntry
.type _SetTLBEntry, @function
.globl func_00311450
.type func_00311450, @function
.ent func_00311450
func_00311450:
_SetTLBEntry:
    addiu $3, $0, 86
    syscall
    jr $31
     nop
.end func_00311450

