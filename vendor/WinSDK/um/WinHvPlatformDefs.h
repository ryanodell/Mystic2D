/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    WinHvPlatformDefs.h

Abstract:

    This module contains the constant, type and structure definitions for
    the Windows Hypervisor User-Mode APIs.

--*/

#ifndef _WINHVAPIDEFS_H_
#define _WINHVAPIDEFS_H_

#if defined(_AMD64_) || defined(_ARM64_)

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#pragma warning(push)
#pragma warning(disable:4201) /* nonstandard extension used: nameless struct/union */
#pragma warning(disable:4214) /* nonstandard extension used: bit field types other than int */
#endif

//
// Virtual Processor Register Definitions
//
#if defined(_AMD64_)
typedef enum WHV_REGISTER_NAME
{
    // X64 General purpose registers
    WHvX64RegisterRax              = 0x00000000,
    WHvX64RegisterRcx              = 0x00000001,
    WHvX64RegisterRdx              = 0x00000002,
    WHvX64RegisterRbx              = 0x00000003,
    WHvX64RegisterRsp              = 0x00000004,
    WHvX64RegisterRbp              = 0x00000005,
    WHvX64RegisterRsi              = 0x00000006,
    WHvX64RegisterRdi              = 0x00000007,
    WHvX64RegisterR8               = 0x00000008,
    WHvX64RegisterR9               = 0x00000009,
    WHvX64RegisterR10              = 0x0000000A,
    WHvX64RegisterR11              = 0x0000000B,
    WHvX64RegisterR12              = 0x0000000C,
    WHvX64RegisterR13              = 0x0000000D,
    WHvX64RegisterR14              = 0x0000000E,
    WHvX64RegisterR15              = 0x0000000F,
    WHvX64RegisterRip              = 0x00000010,
    WHvX64RegisterRflags           = 0x00000011,

    // X64 Segment registers
    WHvX64RegisterEs               = 0x00000012,
    WHvX64RegisterCs               = 0x00000013,
    WHvX64RegisterSs               = 0x00000014,
    WHvX64RegisterDs               = 0x00000015,
    WHvX64RegisterFs               = 0x00000016,
    WHvX64RegisterGs               = 0x00000017,
    WHvX64RegisterLdtr             = 0x00000018,
    WHvX64RegisterTr               = 0x00000019,

    // X64 Table registers
    WHvX64RegisterIdtr             = 0x0000001A,
    WHvX64RegisterGdtr             = 0x0000001B,

    // X64 Control Registers
    WHvX64RegisterCr0              = 0x0000001C,
    WHvX64RegisterCr2              = 0x0000001D,
    WHvX64RegisterCr3              = 0x0000001E,
    WHvX64RegisterCr4              = 0x0000001F,
    WHvX64RegisterCr8              = 0x00000020,

    // X64 Debug Registers
    WHvX64RegisterDr0              = 0x00000021,
    WHvX64RegisterDr1              = 0x00000022,
    WHvX64RegisterDr2              = 0x00000023,
    WHvX64RegisterDr3              = 0x00000024,
    WHvX64RegisterDr6              = 0x00000025,
    WHvX64RegisterDr7              = 0x00000026,

    // X64 Extended Control Registers
    WHvX64RegisterXCr0             = 0x00000027,

    // X64 Virtual Control Registers
    WHvX64RegisterVirtualCr0       = 0x00000028,
    WHvX64RegisterVirtualCr3       = 0x00000029,
    WHvX64RegisterVirtualCr4       = 0x0000002A,
    WHvX64RegisterVirtualCr8       = 0x0000002B,

    // X64 Floating Point and Vector Registers
    WHvX64RegisterXmm0             = 0x00001000,
    WHvX64RegisterXmm1             = 0x00001001,
    WHvX64RegisterXmm2             = 0x00001002,
    WHvX64RegisterXmm3             = 0x00001003,
    WHvX64RegisterXmm4             = 0x00001004,
    WHvX64RegisterXmm5             = 0x00001005,
    WHvX64RegisterXmm6             = 0x00001006,
    WHvX64RegisterXmm7             = 0x00001007,
    WHvX64RegisterXmm8             = 0x00001008,
    WHvX64RegisterXmm9             = 0x00001009,
    WHvX64RegisterXmm10            = 0x0000100A,
    WHvX64RegisterXmm11            = 0x0000100B,
    WHvX64RegisterXmm12            = 0x0000100C,
    WHvX64RegisterXmm13            = 0x0000100D,
    WHvX64RegisterXmm14            = 0x0000100E,
    WHvX64RegisterXmm15            = 0x0000100F,
    WHvX64RegisterFpMmx0           = 0x00001010,
    WHvX64RegisterFpMmx1           = 0x00001011,
    WHvX64RegisterFpMmx2           = 0x00001012,
    WHvX64RegisterFpMmx3           = 0x00001013,
    WHvX64RegisterFpMmx4           = 0x00001014,
    WHvX64RegisterFpMmx5           = 0x00001015,
    WHvX64RegisterFpMmx6           = 0x00001016,
    WHvX64RegisterFpMmx7           = 0x00001017,
    WHvX64RegisterFpControlStatus  = 0x00001018,
    WHvX64RegisterXmmControlStatus = 0x00001019,

    // X64 MSRs
    WHvX64RegisterTsc              = 0x00002000,
    WHvX64RegisterEfer             = 0x00002001,
    WHvX64RegisterKernelGsBase     = 0x00002002,
    WHvX64RegisterApicBase         = 0x00002003,
    WHvX64RegisterPat              = 0x00002004,
    WHvX64RegisterSysenterCs       = 0x00002005,
    WHvX64RegisterSysenterEip      = 0x00002006,
    WHvX64RegisterSysenterEsp      = 0x00002007,
    WHvX64RegisterStar             = 0x00002008,
    WHvX64RegisterLstar            = 0x00002009,
    WHvX64RegisterCstar            = 0x0000200A,
    WHvX64RegisterSfmask           = 0x0000200B,
    WHvX64RegisterInitialApicId    = 0x0000200C,

    WHvX64RegisterMsrMtrrCap         = 0x0000200D,
    WHvX64RegisterMsrMtrrDefType     = 0x0000200E,

    WHvX64RegisterMsrMtrrPhysBase0   = 0x00002010,
    WHvX64RegisterMsrMtrrPhysBase1   = 0x00002011,
    WHvX64RegisterMsrMtrrPhysBase2   = 0x00002012,
    WHvX64RegisterMsrMtrrPhysBase3   = 0x00002013,
    WHvX64RegisterMsrMtrrPhysBase4   = 0x00002014,
    WHvX64RegisterMsrMtrrPhysBase5   = 0x00002015,
    WHvX64RegisterMsrMtrrPhysBase6   = 0x00002016,
    WHvX64RegisterMsrMtrrPhysBase7   = 0x00002017,
    WHvX64RegisterMsrMtrrPhysBase8   = 0x00002018,
    WHvX64RegisterMsrMtrrPhysBase9   = 0x00002019,
    WHvX64RegisterMsrMtrrPhysBaseA   = 0x0000201A,
    WHvX64RegisterMsrMtrrPhysBaseB   = 0x0000201B,
    WHvX64RegisterMsrMtrrPhysBaseC   = 0x0000201C,
    WHvX64RegisterMsrMtrrPhysBaseD   = 0x0000201D,
    WHvX64RegisterMsrMtrrPhysBaseE   = 0x0000201E,
    WHvX64RegisterMsrMtrrPhysBaseF   = 0x0000201F,

    WHvX64RegisterMsrMtrrPhysMask0   = 0x00002040,
    WHvX64RegisterMsrMtrrPhysMask1   = 0x00002041,
    WHvX64RegisterMsrMtrrPhysMask2   = 0x00002042,
    WHvX64RegisterMsrMtrrPhysMask3   = 0x00002043,
    WHvX64RegisterMsrMtrrPhysMask4   = 0x00002044,
    WHvX64RegisterMsrMtrrPhysMask5   = 0x00002045,
    WHvX64RegisterMsrMtrrPhysMask6   = 0x00002046,
    WHvX64RegisterMsrMtrrPhysMask7   = 0x00002047,
    WHvX64RegisterMsrMtrrPhysMask8   = 0x00002048,
    WHvX64RegisterMsrMtrrPhysMask9   = 0x00002049,
    WHvX64RegisterMsrMtrrPhysMaskA   = 0x0000204A,
    WHvX64RegisterMsrMtrrPhysMaskB   = 0x0000204B,
    WHvX64RegisterMsrMtrrPhysMaskC   = 0x0000204C,
    WHvX64RegisterMsrMtrrPhysMaskD   = 0x0000204D,
    WHvX64RegisterMsrMtrrPhysMaskE   = 0x0000204E,
    WHvX64RegisterMsrMtrrPhysMaskF   = 0x0000204F,

    WHvX64RegisterMsrMtrrFix64k00000 = 0x00002070,
    WHvX64RegisterMsrMtrrFix16k80000 = 0x00002071,
    WHvX64RegisterMsrMtrrFix16kA0000 = 0x00002072,
    WHvX64RegisterMsrMtrrFix4kC0000  = 0x00002073,
    WHvX64RegisterMsrMtrrFix4kC8000  = 0x00002074,
    WHvX64RegisterMsrMtrrFix4kD0000  = 0x00002075,
    WHvX64RegisterMsrMtrrFix4kD8000  = 0x00002076,
    WHvX64RegisterMsrMtrrFix4kE0000  = 0x00002077,
    WHvX64RegisterMsrMtrrFix4kE8000  = 0x00002078,
    WHvX64RegisterMsrMtrrFix4kF0000  = 0x00002079,
    WHvX64RegisterMsrMtrrFix4kF8000  = 0x0000207A,

    WHvX64RegisterTscAux           = 0x0000207B,
    WHvX64RegisterBndcfgs          = 0x0000207C,
    WHvX64RegisterMCount           = 0x0000207E,
    WHvX64RegisterACount           = 0x0000207F,
    WHvX64RegisterSpecCtrl         = 0x00002084,
    WHvX64RegisterPredCmd          = 0x00002085,
    WHvX64RegisterTscVirtualOffset = 0x00002087,
    WHvX64RegisterTsxCtrl          = 0x00002088,
    WHvX64RegisterXss              = 0x0000208B,
    WHvX64RegisterUCet             = 0x0000208C,
    WHvX64RegisterSCet             = 0x0000208D,
    WHvX64RegisterSsp              = 0x0000208E,
    WHvX64RegisterPl0Ssp           = 0x0000208F,
    WHvX64RegisterPl1Ssp           = 0x00002090,
    WHvX64RegisterPl2Ssp           = 0x00002091,
    WHvX64RegisterPl3Ssp           = 0x00002092,
    WHvX64RegisterInterruptSspTableAddr = 0x00002093,
    WHvX64RegisterTscDeadline      = 0x00002095,
    WHvX64RegisterTscAdjust        = 0x00002096,
    WHvX64RegisterUmwaitControl    = 0x00002098,
    WHvX64RegisterXfd              = 0x00002099,
    WHvX64RegisterXfdErr           = 0x0000209A,

    // Feature control and nested capability MSRs
    WHvX64RegisterMsrIa32MiscEnable         = 0x000020A0,
    WHvX64RegisterIa32FeatureControl        = 0x000020A1,
    WHvX64RegisterIa32VmxBasic              = 0x000020A2,
    WHvX64RegisterIa32VmxPinbasedCtls       = 0x000020A3,
    WHvX64RegisterIa32VmxProcbasedCtls      = 0x000020A4,
    WHvX64RegisterIa32VmxExitCtls           = 0x000020A5,
    WHvX64RegisterIa32VmxEntryCtls          = 0x000020A6,
    WHvX64RegisterIa32VmxMisc               = 0x000020A7,
    WHvX64RegisterIa32VmxCr0Fixed0          = 0x000020A8,
    WHvX64RegisterIa32VmxCr0Fixed1          = 0x000020A9,
    WHvX64RegisterIa32VmxCr4Fixed0          = 0x000020AA,
    WHvX64RegisterIa32VmxCr4Fixed1          = 0x000020AB,
    WHvX64RegisterIa32VmxVmcsEnum           = 0x000020AC,
    WHvX64RegisterIa32VmxProcbasedCtls2     = 0x000020AD,
    WHvX64RegisterIa32VmxEptVpidCap         = 0x000020AE,
    WHvX64RegisterIa32VmxTruePinbasedCtls   = 0x000020AF,
    WHvX64RegisterIa32VmxTrueProcbasedCtls  = 0x000020B0,
    WHvX64RegisterIa32VmxTrueExitCtls       = 0x000020B1,
    WHvX64RegisterIa32VmxTrueEntryCtls      = 0x000020B2,
    WHvX64RegisterAmdVmHsavePa              = 0x000020B3,
    WHvX64RegisterAmdVmCr                   = 0x000020B4,

    // APIC state (also accessible via WHv(Get/Set)VirtualProcessorInterruptControllerState)
    WHvX64RegisterApicId           = 0x00003002,
    WHvX64RegisterApicVersion      = 0x00003003,
    // X2APIC state (also accessible via WHv(Get/Set)VirtualProcessorInterruptControllerState)
    WHvX64RegisterApicTpr          = 0x00003008,
    WHvX64RegisterApicPpr          = 0x0000300A,
    WHvX64RegisterApicEoi          = 0x0000300B,
    WHvX64RegisterApicLdr          = 0x0000300D,
    WHvX64RegisterApicSpurious     = 0x0000300F,
    WHvX64RegisterApicIsr0         = 0x00003010,
    WHvX64RegisterApicIsr1         = 0x00003011,
    WHvX64RegisterApicIsr2         = 0x00003012,
    WHvX64RegisterApicIsr3         = 0x00003013,
    WHvX64RegisterApicIsr4         = 0x00003014,
    WHvX64RegisterApicIsr5         = 0x00003015,
    WHvX64RegisterApicIsr6         = 0x00003016,
    WHvX64RegisterApicIsr7         = 0x00003017,
    WHvX64RegisterApicTmr0         = 0x00003018,
    WHvX64RegisterApicTmr1         = 0x00003019,
    WHvX64RegisterApicTmr2         = 0x0000301A,
    WHvX64RegisterApicTmr3         = 0x0000301B,
    WHvX64RegisterApicTmr4         = 0x0000301C,
    WHvX64RegisterApicTmr5         = 0x0000301D,
    WHvX64RegisterApicTmr6         = 0x0000301E,
    WHvX64RegisterApicTmr7         = 0x0000301F,
    WHvX64RegisterApicIrr0         = 0x00003020,
    WHvX64RegisterApicIrr1         = 0x00003021,
    WHvX64RegisterApicIrr2         = 0x00003022,
    WHvX64RegisterApicIrr3         = 0x00003023,
    WHvX64RegisterApicIrr4         = 0x00003024,
    WHvX64RegisterApicIrr5         = 0x00003025,
    WHvX64RegisterApicIrr6         = 0x00003026,
    WHvX64RegisterApicIrr7         = 0x00003027,
    WHvX64RegisterApicEse          = 0x00003028,
    WHvX64RegisterApicIcr          = 0x00003030,
    WHvX64RegisterApicLvtTimer     = 0x00003032,
    WHvX64RegisterApicLvtThermal   = 0x00003033,
    WHvX64RegisterApicLvtPerfmon   = 0x00003034,
    WHvX64RegisterApicLvtLint0     = 0x00003035,
    WHvX64RegisterApicLvtLint1     = 0x00003036,
    WHvX64RegisterApicLvtError     = 0x00003037,
    WHvX64RegisterApicInitCount    = 0x00003038,
    WHvX64RegisterApicCurrentCount = 0x00003039,
    WHvX64RegisterApicDivide       = 0x0000303E,
    WHvX64RegisterApicSelfIpi      = 0x0000303F,

    // Synic registers
    WHvRegisterSint0               = 0x00004000,
    WHvRegisterSint1               = 0x00004001,
    WHvRegisterSint2               = 0x00004002,
    WHvRegisterSint3               = 0x00004003,
    WHvRegisterSint4               = 0x00004004,
    WHvRegisterSint5               = 0x00004005,
    WHvRegisterSint6               = 0x00004006,
    WHvRegisterSint7               = 0x00004007,
    WHvRegisterSint8               = 0x00004008,
    WHvRegisterSint9               = 0x00004009,
    WHvRegisterSint10              = 0x0000400A,
    WHvRegisterSint11              = 0x0000400B,
    WHvRegisterSint12              = 0x0000400C,
    WHvRegisterSint13              = 0x0000400D,
    WHvRegisterSint14              = 0x0000400E,
    WHvRegisterSint15              = 0x0000400F,
    WHvRegisterScontrol            = 0x00004010,
    WHvRegisterSversion            = 0x00004011,
    WHvRegisterSiefp               = 0x00004012,
    WHvRegisterSimp                = 0x00004013,
    WHvRegisterEom                 = 0x00004014,

    // Hypervisor defined registers
    WHvRegisterVpRuntime           = 0x00005000,
    WHvX64RegisterHypercall        = 0x00005001,
    WHvRegisterGuestOsId           = 0x00005002,
    WHvRegisterVpAssistPage        = 0x00005013,
    WHvRegisterReferenceTsc        = 0x00005017,
    WHvRegisterReferenceTscSequence = 0x0000501A,
    WHvX64RegisterNestedGuestState  = 0x00005050,
    WHvX64RegisterNestedCurrentVmGpa = 0x00005051,
    WHvX64RegisterNestedVmxInvEpt   = 0x00005052,
    WHvX64RegisterNestedVmxInvVpid  = 0x00005053,

    // Interrupt / Event Registers
    WHvRegisterPendingInterruption = 0x80000000,
    WHvRegisterInterruptState      = 0x80000001,
    WHvRegisterPendingEvent        = 0x80000002,
    WHvRegisterPendingEvent1       = 0x80000003,
    WHvX64RegisterDeliverabilityNotifications = 0x80000004,
    WHvRegisterDeliverabilityNotifications = 0x80000004,
    WHvRegisterInternalActivityState = 0x80000005,
    WHvX64RegisterPendingDebugException = 0x80000006,
    WHvRegisterPendingEvent2       = 0x80000007,
    WHvRegisterPendingEvent3       = 0x80000008,

} WHV_REGISTER_NAME;
#elif defined (_ARM64_)
typedef enum WHV_REGISTER_NAME
{
    //
    // AArch64 System Register Descriptions: General-purpose registers
    //

    WHvArm64RegisterX0                = 0x00020000,
    WHvArm64RegisterX1                = 0x00020001,
    WHvArm64RegisterX2                = 0x00020002,
    WHvArm64RegisterX3                = 0x00020003,
    WHvArm64RegisterX4                = 0x00020004,
    WHvArm64RegisterX5                = 0x00020005,
    WHvArm64RegisterX6                = 0x00020006,
    WHvArm64RegisterX7                = 0x00020007,
    WHvArm64RegisterX8                = 0x00020008,
    WHvArm64RegisterX9                = 0x00020009,
    WHvArm64RegisterX10               = 0x0002000A,
    WHvArm64RegisterX11               = 0x0002000B,
    WHvArm64RegisterX12               = 0x0002000C,
    WHvArm64RegisterX13               = 0x0002000D,
    WHvArm64RegisterX14               = 0x0002000E,
    WHvArm64RegisterX15               = 0x0002000F,
    WHvArm64RegisterX16               = 0x00020010,
    WHvArm64RegisterX17               = 0x00020011,
    WHvArm64RegisterX18               = 0x00020012,
    WHvArm64RegisterX19               = 0x00020013,
    WHvArm64RegisterX20               = 0x00020014,
    WHvArm64RegisterX21               = 0x00020015,
    WHvArm64RegisterX22               = 0x00020016,
    WHvArm64RegisterX23               = 0x00020017,
    WHvArm64RegisterX24               = 0x00020018,
    WHvArm64RegisterX25               = 0x00020019,
    WHvArm64RegisterX26               = 0x0002001A,
    WHvArm64RegisterX27               = 0x0002001B,
    WHvArm64RegisterX28               = 0x0002001C,
    WHvArm64RegisterFp                = 0x0002001D,
    WHvArm64RegisterLr                = 0x0002001E,
    WHvArm64RegisterPc                = 0x00020022,
    WHvArm64RegisterXzr               = 0x0002FFFE,

    //
    // AArch64 System Register Descriptions: Floating-point registers
    //

    WHvArm64RegisterQ0                = 0x00030000,
    WHvArm64RegisterQ1                = 0x00030001,
    WHvArm64RegisterQ2                = 0x00030002,
    WHvArm64RegisterQ3                = 0x00030003,
    WHvArm64RegisterQ4                = 0x00030004,
    WHvArm64RegisterQ5                = 0x00030005,
    WHvArm64RegisterQ6                = 0x00030006,
    WHvArm64RegisterQ7                = 0x00030007,
    WHvArm64RegisterQ8                = 0x00030008,
    WHvArm64RegisterQ9                = 0x00030009,
    WHvArm64RegisterQ10               = 0x0003000A,
    WHvArm64RegisterQ11               = 0x0003000B,
    WHvArm64RegisterQ12               = 0x0003000C,
    WHvArm64RegisterQ13               = 0x0003000D,
    WHvArm64RegisterQ14               = 0x0003000E,
    WHvArm64RegisterQ15               = 0x0003000F,
    WHvArm64RegisterQ16               = 0x00030010,
    WHvArm64RegisterQ17               = 0x00030011,
    WHvArm64RegisterQ18               = 0x00030012,
    WHvArm64RegisterQ19               = 0x00030013,
    WHvArm64RegisterQ20               = 0x00030014,
    WHvArm64RegisterQ21               = 0x00030015,
    WHvArm64RegisterQ22               = 0x00030016,
    WHvArm64RegisterQ23               = 0x00030017,
    WHvArm64RegisterQ24               = 0x00030018,
    WHvArm64RegisterQ25               = 0x00030019,
    WHvArm64RegisterQ26               = 0x0003001A,
    WHvArm64RegisterQ27               = 0x0003001B,
    WHvArm64RegisterQ28               = 0x0003001C,
    WHvArm64RegisterQ29               = 0x0003001D,
    WHvArm64RegisterQ30               = 0x0003001E,
    WHvArm64RegisterQ31               = 0x0003001F,

    //
    // AArch64 System Register Descriptions: Special-purpose registers
    //

    WHvArm64RegisterCurrentEl         = 0x00021003,
    WHvArm64RegisterDaif              = 0x00021004,
    WHvArm64RegisterDit               = 0x00021005,
    WHvArm64RegisterPstate            = 0x00020023,
    WHvArm64RegisterElrEl1            = 0x00040015,
    WHvArm64RegisterFpcr              = 0x00040012,
    WHvArm64RegisterFpsr              = 0x00040013,
    WHvArm64RegisterNzcv              = 0x00021006,
    WHvArm64RegisterPan               = 0x00021007,
    WHvArm64RegisterSp                = 0x0002001F,
    WHvArm64RegisterSpEl0             = 0x00020020,
    WHvArm64RegisterSpEl1             = 0x00020021,
    WHvArm64RegisterSpSel             = 0x00021008,
    WHvArm64RegisterSpsrEl1           = 0x00040014,
    WHvArm64RegisterSsbs              = 0x00021009,
    WHvArm64RegisterTco               = 0x0002100A,
    WHvArm64RegisterUao               = 0x0002100B,

    //
    // AArch64 System Register Descriptions: ID Registers
    //

    WHvArm64RegisterIdAa64Dfr0El1     = 0x00022028,
    WHvArm64RegisterIdAa64Dfr1El1     = 0x00022029,
    WHvArm64RegisterIdAa64Isar0El1    = 0x00022030,
    WHvArm64RegisterIdAa64Isar1El1    = 0x00022031,
    WHvArm64RegisterIdAa64Isar2El1    = 0x00022032,
    WHvArm64RegisterIdAa64Mmfr0El1    = 0x00022038,
    WHvArm64RegisterIdAa64Mmfr1El1    = 0x00022039,
    WHvArm64RegisterIdAa64Mmfr2El1    = 0x0002203A,
    WHvArm64RegisterIdAa64Mmfr3El1    = 0x0002203B,
    WHvArm64RegisterIdAa64Mmfr4El1    = 0x0002203C,
    WHvArm64RegisterIdAa64Pfr0El1     = 0x00022020,
    WHvArm64RegisterIdAa64Pfr1El1     = 0x00022021,
    WHvArm64RegisterIdAa64Pfr2El1     = 0x00022022,
    WHvArm64RegisterIdAa64Smfr0El1    = 0x00022025,
    WHvArm64RegisterIdAa64Zfr0El1     = 0x00022024,
    WHvArm64RegisterIdDfr0El1         = 0x0002200A,
    WHvArm64RegisterIdIsar0El1        = 0x00022010,
    WHvArm64RegisterIdIsar1El1        = 0x00022011,
    WHvArm64RegisterIdIsar2El1        = 0x00022012,
    WHvArm64RegisterIdIsar3El1        = 0x00022013,
    WHvArm64RegisterIdIsar4El1        = 0x00022014,
    WHvArm64RegisterIdIsar5El1        = 0x00022015,
    WHvArm64RegisterIdMmfr0El1        = 0x0002200C,
    WHvArm64RegisterIdMmfr1El1        = 0x0002200D,
    WHvArm64RegisterIdMmfr2El1        = 0x0002200E,
    WHvArm64RegisterIdMmfr3El1        = 0x0002200F,
    WHvArm64RegisterIdPfr0El1         = 0x00022008,
    WHvArm64RegisterIdPfr1El1         = 0x00022009,
    WHvArm64RegisterIdPfr2El1         = 0x0002201C,

    //
    // AArch64 System Register Descriptions: General system control registers
    //

    WHvArm64RegisterApdAKeyHiEl1      = 0x00040026,
    WHvArm64RegisterApdAKeyLoEl1      = 0x00040027,
    WHvArm64RegisterApdBKeyHiEl1      = 0x00040028,
    WHvArm64RegisterApdBKeyLoEl1      = 0x00040029,
    WHvArm64RegisterApgAKeyHiEl1      = 0x0004002A,
    WHvArm64RegisterApgAKeyLoEl1      = 0x0004002B,
    WHvArm64RegisterApiAKeyHiEl1      = 0x0004002C,
    WHvArm64RegisterApiAKeyLoEl1      = 0x0004002D,
    WHvArm64RegisterApiBKeyHiEl1      = 0x0004002E,
    WHvArm64RegisterApiBKeyLoEl1      = 0x0004002F,
    WHvArm64RegisterCcsidrEl1         = 0x00040030,
    WHvArm64RegisterCcsidr2El1        = 0x00040031,
    WHvArm64RegisterClidrEl1          = 0x00040032,
    WHvArm64RegisterContextidrEl1     = 0x0004000D,
    WHvArm64RegisterCpacrEl1          = 0x00040004,
    WHvArm64RegisterCsselrEl1         = 0x00040035,
    WHvArm64RegisterCtrEl0            = 0x00040036,
    WHvArm64RegisterDczidEl0          = 0x00040038,
    WHvArm64RegisterEsrEl1            = 0x00040008,
    WHvArm64RegisterFarEl1            = 0x00040009,
    WHvArm64RegisterIsrEl1            = 0x0004004A,
    WHvArm64RegisterMairEl1           = 0x0004000B,
    WHvArm64RegisterMidrEl1           = 0x00040051,
    WHvArm64RegisterMpidrEl1          = 0x00040001,
    WHvArm64RegisterMvfr0El1          = 0x00040052,
    WHvArm64RegisterMvfr1El1          = 0x00040053,
    WHvArm64RegisterMvfr2El1          = 0x00040054,
    WHvArm64RegisterParEl1            = 0x0004000A,
    WHvArm64RegisterRevidrEl1         = 0x00040055,
    WHvArm64RegisterRgsrEl1           = 0x00040056,
    WHvArm64RegisterRndr              = 0x00040057,
    WHvArm64RegisterRndrrs            = 0x00040058,
    WHvArm64RegisterSctlrEl1          = 0x00040002,
    WHvArm64RegisterTcrEl1            = 0x00040007,
    WHvArm64RegisterTpidrEl0          = 0x00040011,
    WHvArm64RegisterTpidrEl1          = 0x0004000E,
    WHvArm64RegisterTpidrroEl0        = 0x00040010,
    WHvArm64RegisterTtbr0El1          = 0x00040005,
    WHvArm64RegisterTtbr1El1          = 0x00040006,
    WHvArm64RegisterVbarEl1           = 0x0004000C,

    //
    // AArch64 System Register Descriptions: Debug Registers
    //

    WHvArm64RegisterDbgbcr0El1        = 0x00050000,
    WHvArm64RegisterDbgbcr1El1        = 0x00050001,
    WHvArm64RegisterDbgbcr2El1        = 0x00050002,
    WHvArm64RegisterDbgbcr3El1        = 0x00050003,
    WHvArm64RegisterDbgbcr4El1        = 0x00050004,
    WHvArm64RegisterDbgbcr5El1        = 0x00050005,
    WHvArm64RegisterDbgbcr6El1        = 0x00050006,
    WHvArm64RegisterDbgbcr7El1        = 0x00050007,
    WHvArm64RegisterDbgbcr8El1        = 0x00050008,
    WHvArm64RegisterDbgbcr9El1        = 0x00050009,
    WHvArm64RegisterDbgbcr10El1       = 0x0005000A,
    WHvArm64RegisterDbgbcr11El1       = 0x0005000B,
    WHvArm64RegisterDbgbcr12El1       = 0x0005000C,
    WHvArm64RegisterDbgbcr13El1       = 0x0005000D,
    WHvArm64RegisterDbgbcr14El1       = 0x0005000E,
    WHvArm64RegisterDbgbcr15El1       = 0x0005000F,
    WHvArm64RegisterDbgbvr0El1        = 0x00050020,
    WHvArm64RegisterDbgbvr1El1        = 0x00050021,
    WHvArm64RegisterDbgbvr2El1        = 0x00050022,
    WHvArm64RegisterDbgbvr3El1        = 0x00050023,
    WHvArm64RegisterDbgbvr4El1        = 0x00050024,
    WHvArm64RegisterDbgbvr5El1        = 0x00050025,
    WHvArm64RegisterDbgbvr6El1        = 0x00050026,
    WHvArm64RegisterDbgbvr7El1        = 0x00050027,
    WHvArm64RegisterDbgbvr8El1        = 0x00050028,
    WHvArm64RegisterDbgbvr9El1        = 0x00050029,
    WHvArm64RegisterDbgbvr10El1       = 0x0005002A,
    WHvArm64RegisterDbgbvr11El1       = 0x0005002B,
    WHvArm64RegisterDbgbvr12El1       = 0x0005002C,
    WHvArm64RegisterDbgbvr13El1       = 0x0005002D,
    WHvArm64RegisterDbgbvr14El1       = 0x0005002E,
    WHvArm64RegisterDbgbvr15El1       = 0x0005002F,
    WHvArm64RegisterDbgprcrEl1        = 0x00050045,
    WHvArm64RegisterDbgwcr0El1        = 0x00050010,
    WHvArm64RegisterDbgwcr1El1        = 0x00050011,
    WHvArm64RegisterDbgwcr2El1        = 0x00050012,
    WHvArm64RegisterDbgwcr3El1        = 0x00050013,
    WHvArm64RegisterDbgwcr4El1        = 0x00050014,
    WHvArm64RegisterDbgwcr5El1        = 0x00050015,
    WHvArm64RegisterDbgwcr6El1        = 0x00050016,
    WHvArm64RegisterDbgwcr7El1        = 0x00050017,
    WHvArm64RegisterDbgwcr8El1        = 0x00050018,
    WHvArm64RegisterDbgwcr9El1        = 0x00050019,
    WHvArm64RegisterDbgwcr10El1       = 0x0005001A,
    WHvArm64RegisterDbgwcr11El1       = 0x0005001B,
    WHvArm64RegisterDbgwcr12El1       = 0x0005001C,
    WHvArm64RegisterDbgwcr13El1       = 0x0005001D,
    WHvArm64RegisterDbgwcr14El1       = 0x0005001E,
    WHvArm64RegisterDbgwcr15El1       = 0x0005001F,
    WHvArm64RegisterDbgwvr0El1        = 0x00050030,
    WHvArm64RegisterDbgwvr1El1        = 0x00050031,
    WHvArm64RegisterDbgwvr2El1        = 0x00050032,
    WHvArm64RegisterDbgwvr3El1        = 0x00050033,
    WHvArm64RegisterDbgwvr4El1        = 0x00050034,
    WHvArm64RegisterDbgwvr5El1        = 0x00050035,
    WHvArm64RegisterDbgwvr6El1        = 0x00050036,
    WHvArm64RegisterDbgwvr7El1        = 0x00050037,
    WHvArm64RegisterDbgwvr8El1        = 0x00050038,
    WHvArm64RegisterDbgwvr9El1        = 0x00050039,
    WHvArm64RegisterDbgwvr10El1       = 0x0005003A,
    WHvArm64RegisterDbgwvr11El1       = 0x0005003B,
    WHvArm64RegisterDbgwvr12El1       = 0x0005003C,
    WHvArm64RegisterDbgwvr13El1       = 0x0005003D,
    WHvArm64RegisterDbgwvr14El1       = 0x0005003E,
    WHvArm64RegisterDbgwvr15El1       = 0x0005003F,
    WHvArm64RegisterMdrarEl1          = 0x0005004C,
    WHvArm64RegisterMdscrEl1          = 0x0005004D,
    WHvArm64RegisterOsdlrEl1          = 0x0005004E,
    WHvArm64RegisterOslarEl1          = 0x00050052,
    WHvArm64RegisterOslsrEl1          = 0x00050053,

    //
    // AArch64 System Register Descriptions: Performance Monitors Registers
    //

    WHvArm64RegisterPmccfiltrEl0      = 0x00052000,
    WHvArm64RegisterPmccntrEl0        = 0x00052001,
    WHvArm64RegisterPmceid0El0        = 0x00052002,
    WHvArm64RegisterPmceid1El0        = 0x00052003,
    WHvArm64RegisterPmcntenclrEl0     = 0x00052004,
    WHvArm64RegisterPmcntensetEl0     = 0x00052005,
    WHvArm64RegisterPmcrEl0           = 0x00052006,
    WHvArm64RegisterPmevcntr0El0      = 0x00052007,
    WHvArm64RegisterPmevcntr1El0      = 0x00052008,
    WHvArm64RegisterPmevcntr2El0      = 0x00052009,
    WHvArm64RegisterPmevcntr3El0      = 0x0005200A,
    WHvArm64RegisterPmevcntr4El0      = 0x0005200B,
    WHvArm64RegisterPmevcntr5El0      = 0x0005200C,
    WHvArm64RegisterPmevcntr6El0      = 0x0005200D,
    WHvArm64RegisterPmevcntr7El0      = 0x0005200E,
    WHvArm64RegisterPmevcntr8El0      = 0x0005200F,
    WHvArm64RegisterPmevcntr9El0      = 0x00052010,
    WHvArm64RegisterPmevcntr10El0     = 0x00052011,
    WHvArm64RegisterPmevcntr11El0     = 0x00052012,
    WHvArm64RegisterPmevcntr12El0     = 0x00052013,
    WHvArm64RegisterPmevcntr13El0     = 0x00052014,
    WHvArm64RegisterPmevcntr14El0     = 0x00052015,
    WHvArm64RegisterPmevcntr15El0     = 0x00052016,
    WHvArm64RegisterPmevcntr16El0     = 0x00052017,
    WHvArm64RegisterPmevcntr17El0     = 0x00052018,
    WHvArm64RegisterPmevcntr18El0     = 0x00052019,
    WHvArm64RegisterPmevcntr19El0     = 0x0005201A,
    WHvArm64RegisterPmevcntr20El0     = 0x0005201B,
    WHvArm64RegisterPmevcntr21El0     = 0x0005201C,
    WHvArm64RegisterPmevcntr22El0     = 0x0005201D,
    WHvArm64RegisterPmevcntr23El0     = 0x0005201E,
    WHvArm64RegisterPmevcntr24El0     = 0x0005201F,
    WHvArm64RegisterPmevcntr25El0     = 0x00052020,
    WHvArm64RegisterPmevcntr26El0     = 0x00052021,
    WHvArm64RegisterPmevcntr27El0     = 0x00052022,
    WHvArm64RegisterPmevcntr28El0     = 0x00052023,
    WHvArm64RegisterPmevcntr29El0     = 0x00052024,
    WHvArm64RegisterPmevcntr30El0     = 0x00052025,
    WHvArm64RegisterPmevtyper0El0     = 0x00052026,
    WHvArm64RegisterPmevtyper1El0     = 0x00052027,
    WHvArm64RegisterPmevtyper2El0     = 0x00052028,
    WHvArm64RegisterPmevtyper3El0     = 0x00052029,
    WHvArm64RegisterPmevtyper4El0     = 0x0005202A,
    WHvArm64RegisterPmevtyper5El0     = 0x0005202B,
    WHvArm64RegisterPmevtyper6El0     = 0x0005202C,
    WHvArm64RegisterPmevtyper7El0     = 0x0005202D,
    WHvArm64RegisterPmevtyper8El0     = 0x0005202E,
    WHvArm64RegisterPmevtyper9El0     = 0x0005202F,
    WHvArm64RegisterPmevtyper10El0    = 0x00052030,
    WHvArm64RegisterPmevtyper11El0    = 0x00052031,
    WHvArm64RegisterPmevtyper12El0    = 0x00052032,
    WHvArm64RegisterPmevtyper13El0    = 0x00052033,
    WHvArm64RegisterPmevtyper14El0    = 0x00052034,
    WHvArm64RegisterPmevtyper15El0    = 0x00052035,
    WHvArm64RegisterPmevtyper16El0    = 0x00052036,
    WHvArm64RegisterPmevtyper17El0    = 0x00052037,
    WHvArm64RegisterPmevtyper18El0    = 0x00052038,
    WHvArm64RegisterPmevtyper19El0    = 0x00052039,
    WHvArm64RegisterPmevtyper20El0    = 0x0005203A,
    WHvArm64RegisterPmevtyper21El0    = 0x0005203B,
    WHvArm64RegisterPmevtyper22El0    = 0x0005203C,
    WHvArm64RegisterPmevtyper23El0    = 0x0005203D,
    WHvArm64RegisterPmevtyper24El0    = 0x0005203E,
    WHvArm64RegisterPmevtyper25El0    = 0x0005203F,
    WHvArm64RegisterPmevtyper26El0    = 0x00052040,
    WHvArm64RegisterPmevtyper27El0    = 0x00052041,
    WHvArm64RegisterPmevtyper28El0    = 0x00052042,
    WHvArm64RegisterPmevtyper29El0    = 0x00052043,
    WHvArm64RegisterPmevtyper30El0    = 0x00052044,
    WHvArm64RegisterPmintenclrEl1     = 0x00052045,
    WHvArm64RegisterPmintensetEl1     = 0x00052046,
    WHvArm64RegisterPmovsclrEl0       = 0x00052048,
    WHvArm64RegisterPmovssetEl0       = 0x00052049,
    WHvArm64RegisterPmselrEl0         = 0x0005204A,
    WHvArm64RegisterPmswincEl0        = 0x0005204B,
    WHvArm64RegisterPmuserenrEl0      = 0x0005204C,
    WHvArm64RegisterPmxevcntrEl0      = 0x0005204D,
    WHvArm64RegisterPmxevtyperEl0     = 0x0005204E,

    //
    // AArch64 System Register Descriptions: Generic Timer Registers
    //

    WHvArm64RegisterCntfrqEl0         = 0x00058000,
    WHvArm64RegisterCntkctlEl1        = 0x00058008,
    WHvArm64RegisterCntvCtlEl0        = 0x0005800E,
    WHvArm64RegisterCntvCvalEl0       = 0x0005800F,
    WHvArm64RegisterCntvTvalEl0       = 0x00058010,
    WHvArm64RegisterCntvctEl0         = 0x00058011,

    //
    // ARM GIC (System Registers): AArch64 System Register Descriptions
    //

    WHvArm64RegisterIccAp1R0El1       = 0x00060000,
    WHvArm64RegisterIccAp1R1El1       = 0x00060001,
    WHvArm64RegisterIccAp1R2El1       = 0x00060002,
    WHvArm64RegisterIccAp1R3El1       = 0x00060003,
    WHvArm64RegisterIccAsgi1REl1      = 0x00060004,
    WHvArm64RegisterIccBpr1El1        = 0x00060005,
    WHvArm64RegisterIccCtlrEl1        = 0x00060006,
    WHvArm64RegisterIccDirEl1         = 0x00060007,
    WHvArm64RegisterIccEoir1El1       = 0x00060008,
    WHvArm64RegisterIccHppir1El1      = 0x00060009,
    WHvArm64RegisterIccIar1El1        = 0x0006000A,
    WHvArm64RegisterIccIgrpen1El1     = 0x0006000B,
    WHvArm64RegisterIccPmrEl1         = 0x0006000C,
    WHvArm64RegisterIccRprEl1         = 0x0006000D,
    WHvArm64RegisterIccSgi1REl1       = 0x0006000E,
    WHvArm64RegisterIccSreEl1         = 0x0006000F,

    // Synic registers
    WHvRegisterSint0               = 0x000A0000,
    WHvRegisterSint1               = 0x000A0001,
    WHvRegisterSint2               = 0x000A0002,
    WHvRegisterSint3               = 0x000A0003,
    WHvRegisterSint4               = 0x000A0004,
    WHvRegisterSint5               = 0x000A0005,
    WHvRegisterSint6               = 0x000A0006,
    WHvRegisterSint7               = 0x000A0007,
    WHvRegisterSint8               = 0x000A0008,
    WHvRegisterSint9               = 0x000A0009,
    WHvRegisterSint10              = 0x000A000A,
    WHvRegisterSint11              = 0x000A000B,
    WHvRegisterSint12              = 0x000A000C,
    WHvRegisterSint13              = 0x000A000D,
    WHvRegisterSint14              = 0x000A000E,
    WHvRegisterSint15              = 0x000A000F,
    WHvRegisterScontrol            = 0x000A0010,
    WHvRegisterSversion            = 0x000A0011,
    WHvRegisterSifp                = 0x000A0012,
    WHvRegisterSipp                = 0x000A0013,
    WHvRegisterEom                 = 0x000A0014,

    // Hypervisor defined registers
    WHvRegisterVpRuntime           = 0x00090000,

    WHvRegisterGuestOsId           = 0x00090002,
    WHvRegisterVpAssistPage        = 0x00090013,
    WHvArm64RegisterPartitionInfoPage = 0x00090015,
    WHvRegisterReferenceTsc        = 0x00090017,
    WHvRegisterReferenceTscSequence = 0x0009001A,

    WHvRegisterPendingEvent0       = 0x00010004,
    WHvRegisterPendingEvent1       = 0x00010005,
    WHvRegisterDeliverabilityNotifications = 0x00010006,
    WHvRegisterInternalActivityState = 0x00000004,
    WHvRegisterPendingEvent2       = 0x00010008,
    WHvRegisterPendingEvent3       = 0x00010009,
} WHV_REGISTER_NAME;

#define WHvRegisterSiefp WHvRegisterSifp
#define WHvRegisterSimp WHvRegisterSipp
#define WHvRegisterPendingEvent WHvRegisterPendingEvent0

#endif // _ARCH_

typedef union DECLSPEC_ALIGN(16) WHV_UINT128
{
    struct
    {
        UINT64  Low64;
        UINT64  High64;
    };

    UINT32  Dword[4];
} WHV_UINT128;

C_ASSERT(sizeof(WHV_UINT128) == 16);

#if defined(_AMD64_)

typedef union WHV_X64_FP_REGISTER
{
    struct
    {
        UINT64 Mantissa;
        UINT64 BiasedExponent:15;
        UINT64 Sign:1;
        UINT64 Reserved:48;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_FP_REGISTER;

C_ASSERT(sizeof(WHV_X64_FP_REGISTER) == 16);

typedef union WHV_X64_FP_CONTROL_STATUS_REGISTER
{
    struct
    {
        UINT16 FpControl;
        UINT16 FpStatus;
        UINT8  FpTag;
        UINT8  Reserved;
        UINT16 LastFpOp;
        union
        {
            // Long Mode
            UINT64 LastFpRip;

            // 32 Bit Mode
            struct
            {
                UINT32 LastFpEip;
                UINT16 LastFpCs;
                UINT16 Reserved2;
            };
        };
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_FP_CONTROL_STATUS_REGISTER;

C_ASSERT(sizeof(WHV_X64_FP_CONTROL_STATUS_REGISTER) == 16);

typedef union WHV_X64_XMM_CONTROL_STATUS_REGISTER
{
    struct
    {
        union
        {
            // Long Mode
            UINT64 LastFpRdp;

            // 32 Bit Mode
            struct
            {
                UINT32 LastFpDp;
                UINT16 LastFpDs;
                UINT16 Reserved;
            };
        };
        UINT32 XmmStatusControl;
        UINT32 XmmStatusControlMask;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_XMM_CONTROL_STATUS_REGISTER;

C_ASSERT(sizeof(WHV_X64_FP_CONTROL_STATUS_REGISTER) == 16);

typedef struct WHV_X64_SEGMENT_REGISTER
{
    UINT64 Base;
    UINT32 Limit;
    UINT16 Selector;

    union
    {
        struct
        {
            UINT16 SegmentType:4;
            UINT16 NonSystemSegment:1;
            UINT16 DescriptorPrivilegeLevel:2;
            UINT16 Present:1;
            UINT16 Reserved:4;
            UINT16 Available:1;
            UINT16 Long:1;
            UINT16 Default:1;
            UINT16 Granularity:1;
        };

        UINT16 Attributes;
    };
} WHV_X64_SEGMENT_REGISTER;

C_ASSERT(sizeof(WHV_X64_SEGMENT_REGISTER) == 16);

typedef struct WHV_X64_TABLE_REGISTER
{
    UINT16     Pad[3];
    UINT16     Limit;
    UINT64     Base;
} WHV_X64_TABLE_REGISTER;

C_ASSERT(sizeof(WHV_X64_TABLE_REGISTER) == 16);

typedef union WHV_X64_INTERRUPT_STATE_REGISTER
{
    struct
    {
        UINT64 InterruptShadow:1;
        UINT64 NmiMasked:1;
        UINT64 Reserved:62;
    };

    UINT64 AsUINT64;
} WHV_X64_INTERRUPT_STATE_REGISTER;

C_ASSERT(sizeof(WHV_X64_INTERRUPT_STATE_REGISTER) == 8);

typedef union WHV_X64_PENDING_INTERRUPTION_REGISTER
{
    struct
    {
        UINT32 InterruptionPending:1;
        UINT32 InterruptionType:3;  // WHV_X64_PENDING_INTERRUPTION_TYPE
        UINT32 DeliverErrorCode:1;
        UINT32 InstructionLength:4;
        UINT32 NestedEvent:1;
        UINT32 Reserved:6;
        UINT32 InterruptionVector:16;
        UINT32 ErrorCode;
    };

    UINT64 AsUINT64;
} WHV_X64_PENDING_INTERRUPTION_REGISTER;

C_ASSERT(sizeof(WHV_X64_PENDING_INTERRUPTION_REGISTER) == 8);

typedef enum WHV_X64_PENDING_EVENT_TYPE
{
    WHvX64PendingEventException = 0,
    WHvX64PendingEventExtInt    = 5,
    WHvX64PendingEventSvmNestedExit = 7,
    WHvX64PendingEventVmxNestedExit = 8,
} WHV_X64_PENDING_EVENT_TYPE;

typedef union WHV_X64_PENDING_EXCEPTION_EVENT
{
    struct
    {
        UINT32 EventPending         : 1;
        UINT32 EventType            : 3; // Must be WHvX64PendingEventException
        UINT32 Reserved0            : 4;

        UINT32 DeliverErrorCode     : 1;
        UINT32 Reserved1            : 7;
        UINT32 Vector               : 16;
        UINT32 ErrorCode;
        UINT64 ExceptionParameter;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_EXCEPTION_EVENT;

C_ASSERT(sizeof(WHV_X64_PENDING_EXCEPTION_EVENT) == 16);

typedef union WHV_X64_PENDING_EXT_INT_EVENT
{
    struct
    {
        UINT64 EventPending     : 1;
        UINT64 EventType        : 3; // Must be WHvX64PendingEventExtInt
        UINT64 Reserved0        : 4;
        UINT64 Vector           : 8;
        UINT64 Reserved1        : 48;

        UINT64 Reserved2;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_EXT_INT_EVENT;

C_ASSERT(sizeof(WHV_X64_PENDING_EXT_INT_EVENT) == 16);

//
// Define pending event registers for nested VMEXITs. For AMD, this spans
// four 128-bit registers. On Intel, this spans three 128-bit registers.
//

typedef union WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT0
{
    struct
    {
        UINT64 EventPending : 1;
        UINT64 EventType : 4; // Must be WHvX64PendingEventSvmNestedExit
        UINT64 Reserved0 : 3;
        UINT64 InstructionBytesValid : 1;
        UINT64 Reserved1 : 55;

        UINT64 ExitCode;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT0;

typedef union WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT1
{
    struct
    {
        UINT64 ExitInfo1;
        UINT64 ExitInfo2;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT1;

typedef union WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT2
{
    struct
    {
        UINT64 NextRip;
        UINT8 InstructionBytesFetchedCount;
        UINT8 InstructionBytes[7];
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT2;

typedef union WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT3
{
    struct
    {
        UINT8 InstructionBytes[8];
        UINT64 Reserved2;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT3;

C_ASSERT(sizeof(WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT0) == 16);
C_ASSERT(sizeof(WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT1) == 16);
C_ASSERT(sizeof(WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT2) == 16);
C_ASSERT(sizeof(WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT3) == 16);

typedef union WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT0
{
    struct
    {
        UINT32 EventPending : 1;
        UINT32 EventType : 4; // Must be WHvX64PendingEventVmxNestedExit
        UINT32 Reserved0 : 27;
        UINT32 ExitReason;

        UINT64 ExitQualification;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT0;

typedef union WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT1
{
    struct
    {
        UINT32 InstructionLength;
        UINT32 InstructionInfo;

        UINT32 ExitInterruptionInfo;
        UINT32 ExitExceptionErrorCode;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT1;

typedef union WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT2
{
    struct
    {
        UINT64 GuestLinearAddress;
        UINT64 GuestPhysicalAddress;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT2;

C_ASSERT(sizeof(WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT0) == 16);
C_ASSERT(sizeof(WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT1) == 16);
C_ASSERT(sizeof(WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT2) == 16);

typedef union WHV_X64_NESTED_INVEPT_REGISTER
{
    struct
    {
        UINT8 Type;
        UINT8 Reserved[7];
        UINT64 Eptp;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_NESTED_INVEPT_REGISTER;

C_ASSERT(sizeof(WHV_X64_NESTED_INVEPT_REGISTER) == 16);

typedef union WHV_X64_NESTED_INVVPID_REGISTER
{
    struct
    {
        UINT8 Type;
        UINT8 Reserved[3];
        UINT32 Vpid;

        UINT64 LinearAddress;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_NESTED_INVVPID_REGISTER;

C_ASSERT(sizeof(WHV_X64_NESTED_INVVPID_REGISTER) == 16);

typedef union WHV_X64_NESTED_GUEST_STATE
{
    struct
    {
        UINT64 NestedVirtActive:1;
        UINT64 NestedGuestMode:1;
        UINT64 VmEntryPending:1;
        UINT64 Reserved0:61;

        UINT64 Reserved1;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_NESTED_GUEST_STATE;

C_ASSERT(sizeof(WHV_X64_NESTED_GUEST_STATE) == 16);

#endif // defined(_AMD64_)

typedef union WHV_DELIVERABILITY_NOTIFICATIONS_REGISTER
{
    struct
    {
#if defined(_AMD64_)
        UINT64 NmiNotification:1;
        UINT64 InterruptNotification:1;
        UINT64 InterruptPriority:4;
        UINT64 Reserved:42;
#elif defined(_ARM64_)
        UINT64 Reserved:48;
#endif
        UINT64 Sint:16;
    };

    UINT64 AsUINT64;
} WHV_DELIVERABILITY_NOTIFICATIONS_REGISTER, WHV_X64_DELIVERABILITY_NOTIFICATIONS_REGISTER;

C_ASSERT(sizeof(WHV_DELIVERABILITY_NOTIFICATIONS_REGISTER) == 8);

typedef union WHV_INTERNAL_ACTIVITY_REGISTER
{
    struct
    {
        UINT64 StartupSuspend : 1;
        UINT64 HaltSuspend : 1;
        UINT64 IdleSuspend : 1;
        UINT64 Reserved:61;
    };

    UINT64 AsUINT64;
} WHV_INTERNAL_ACTIVITY_REGISTER;

C_ASSERT(sizeof(WHV_INTERNAL_ACTIVITY_REGISTER) == 8);

#if defined(_AMD64_)

typedef union WHV_X64_PENDING_DEBUG_EXCEPTION
{
    UINT64 AsUINT64;

    struct
    {
        UINT64 Breakpoint0 : 1;
        UINT64 Breakpoint1 : 1;
        UINT64 Breakpoint2 : 1;
        UINT64 Breakpoint3 : 1;
        UINT64 SingleStep : 1;
        UINT64 Reserved0 : 59;
    };

} WHV_X64_PENDING_DEBUG_EXCEPTION;

C_ASSERT(sizeof(WHV_X64_PENDING_DEBUG_EXCEPTION) == 8);

#endif // defined(_AMD64_)

//
// Register values
//
typedef union WHV_REGISTER_VALUE
{
    WHV_UINT128 Reg128;
    UINT64 Reg64;
    UINT32 Reg32;
    UINT16 Reg16;
    UINT8 Reg8;
    WHV_INTERNAL_ACTIVITY_REGISTER InternalActivity;
    WHV_DELIVERABILITY_NOTIFICATIONS_REGISTER DeliverabilityNotifications;

#if defined(_AMD64_)
    WHV_X64_FP_REGISTER Fp;
    WHV_X64_FP_CONTROL_STATUS_REGISTER FpControlStatus;
    WHV_X64_XMM_CONTROL_STATUS_REGISTER XmmControlStatus;
    WHV_X64_SEGMENT_REGISTER Segment;
    WHV_X64_TABLE_REGISTER Table;
    WHV_X64_INTERRUPT_STATE_REGISTER InterruptState;
    WHV_X64_PENDING_INTERRUPTION_REGISTER PendingInterruption;
    WHV_X64_PENDING_EXCEPTION_EVENT ExceptionEvent;
    WHV_X64_PENDING_EXT_INT_EVENT ExtIntEvent;
    WHV_X64_PENDING_DEBUG_EXCEPTION PendingDebugException;
    WHV_X64_NESTED_GUEST_STATE NestedState;
    WHV_X64_NESTED_INVEPT_REGISTER InvEpt;
    WHV_X64_NESTED_INVVPID_REGISTER InvVpid;
    WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT0 SvmNestedExit0;
    WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT1 SvmNestedExit1;
    WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT2 SvmNestedExit2;
    WHV_X64_PENDING_SVM_NESTED_EXIT_EVENT3 SvmNestedExit3;
    WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT0 VmxNestedExit0;
    WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT1 VmxNestedExit1;
    WHV_X64_PENDING_VMX_NESTED_EXIT_EVENT2 VmxNestedExit2;
#endif
} WHV_REGISTER_VALUE;

C_ASSERT(sizeof(WHV_REGISTER_VALUE) == 16);

//
// Platform capabilities
//
typedef enum WHV_CAPABILITY_CODE
{
    // Capabilities of the API implementation
    WHvCapabilityCodeHypervisorPresent                = 0x00000000,
    WHvCapabilityCodeFeatures                         = 0x00000001,
    WHvCapabilityCodeExtendedVmExits                  = 0x00000002,
#if defined(_AMD64_)
    WHvCapabilityCodeExceptionExitBitmap              = 0x00000003,
    WHvCapabilityCodeX64MsrExitBitmap                 = 0x00000004,
#endif
    WHvCapabilityCodeGpaRangePopulateFlags            = 0x00000005,
    WHvCapabilityCodeSchedulerFeatures                = 0x00000006,

    // Capabilities of the system's processor
    WHvCapabilityCodeProcessorVendor                 = 0x00001000,
    WHvCapabilityCodeProcessorFeatures               = 0x00001001,
    WHvCapabilityCodeProcessorClFlushSize            = 0x00001002,
#if defined(_AMD64_)
    WHvCapabilityCodeProcessorXsaveFeatures          = 0x00001003,
#endif
    WHvCapabilityCodeProcessorClockFrequency         = 0x00001004,
#if defined(_AMD64_)
    WHvCapabilityCodeInterruptClockFrequency         = 0x00001005,
#endif
    WHvCapabilityCodeProcessorFeaturesBanks          = 0x00001006,
    WHvCapabilityCodeProcessorFrequencyCap           = 0x00001007,
    WHvCapabilityCodeSyntheticProcessorFeaturesBanks = 0x00001008,
#if defined(_AMD64_)
    WHvCapabilityCodeProcessorPerfmonFeatures        = 0x00001009,
#endif
    WHvCapabilityCodePhysicalAddressWidth            = 0x0000100A,
#if defined(_AMD64_)
    // Nested-virtualization related capabilities
    WHvCapabilityCodeVmxBasic                        = 0x00002000,
    WHvCapabilityCodeVmxPinbasedCtls                 = 0x00002001,
    WHvCapabilityCodeVmxProcbasedCtls                = 0x00002002,
    WHvCapabilityCodeVmxExitCtls                     = 0x00002003,
    WHvCapabilityCodeVmxEntryCtls                    = 0x00002004,
    WHvCapabilityCodeVmxMisc                         = 0x00002005,
    WHvCapabilityCodeVmxCr0Fixed0                    = 0x00002006,
    WHvCapabilityCodeVmxCr0Fixed1                    = 0x00002007,
    WHvCapabilityCodeVmxCr4Fixed0                    = 0x00002008,
    WHvCapabilityCodeVmxCr4Fixed1                    = 0x00002009,
    WHvCapabilityCodeVmxVmcsEnum                     = 0x0000200A,
    WHvCapabilityCodeVmxProcbasedCtls2               = 0x0000200B,
    WHvCapabilityCodeVmxEptVpidCap                   = 0x0000200C,
    WHvCapabilityCodeVmxTruePinbasedCtls             = 0x0000200D,
    WHvCapabilityCodeVmxTrueProcbasedCtls            = 0x0000200E,
    WHvCapabilityCodeVmxTrueExitCtls                 = 0x0000200F,
    WHvCapabilityCodeVmxTrueEntryCtls                = 0x00002010,
#endif
} WHV_CAPABILITY_CODE;

//
// Return values for WhvCapabilityCodeFeatures
//
typedef union WHV_CAPABILITY_FEATURES
{
    struct
    {
        UINT64 PartialUnmap : 1;
#if defined(_AMD64_)
        UINT64 LocalApicEmulation : 1;
        UINT64 Xsave : 1;
#else
        UINT64 ReservedArm0 : 2;
#endif
        UINT64 DirtyPageTracking : 1;
        UINT64 SpeculationControl : 1;
#if defined(_AMD64_)
        UINT64 ApicRemoteRead : 1;
#else
        UINT64 ReservedArm1 : 1;
#endif
        UINT64 IdleSuspend : 1;
        UINT64 VirtualPciDeviceSupport : 1;
        UINT64 IommuSupport : 1;
        UINT64 VpHotAddRemove : 1;
        UINT64 Reserved : 54;
    };

    UINT64 AsUINT64;
} WHV_CAPABILITY_FEATURES;

C_ASSERT(sizeof(WHV_CAPABILITY_FEATURES) == 8);

//
// Return values for WhvCapabilityCodeExtendedVmExits and input buffer for
// WHvPartitionPropertyCodeExtendedVmExits
//
typedef union WHV_EXTENDED_VM_EXITS
{
    struct
    {
#if defined(_AMD64_)
        UINT64 X64CpuidExit               : 1; // WHvRunVpExitReasonX64CPUID supported
        UINT64 X64MsrExit                 : 1; // WHvRunVpExitX64ReasonMSRAccess supported
        UINT64 ExceptionExit              : 1; // WHvRunVpExitReasonException supported
        UINT64 X64RdtscExit               : 1; // WHvRunVpExitReasonX64Rdtsc supported
        UINT64 X64ApicSmiExitTrap         : 1; // WHvRunVpExitReasonX64ApicSmiTrap supported
#else
        UINT64 ReservedArm0               : 5;
#endif
        UINT64 HypercallExit              : 1; // WHvRunVpExitReasonHypercall supported
#if defined(_AMD64_)
        UINT64 X64ApicInitSipiExitTrap    : 1; // WHvRunVpExitReasonX64ApicInitSipiTrap supported
        UINT64 X64ApicWriteLint0ExitTrap  : 1; // WHvRunVpExitReasonX64ApicWriteTrap supported
        UINT64 X64ApicWriteLint1ExitTrap  : 1; // WHvRunVpExitReasonX64ApicWriteTrap supported
        UINT64 X64ApicWriteSvrExitTrap    : 1; // WHvRunVpExitReasonX64ApicWriteTrap supported
#else
        UINT64 ReservedArm1               : 4;
#endif
        UINT64 UnknownSynicConnection     : 1; // WHvRunVpExitReasonHypercall supported for unknown synic connection to HvSignalEvent
        UINT64 RetargetUnknownVpciDevice  : 1; // WHvRunVpExitReasonHypercall supported for unknown device to HvRetargetDeviceInterrupt
#if defined(_AMD64_)
        UINT64 X64ApicWriteLdrExitTrap    : 1; // WHvRunVpExitReasonX64ApicWriteTrap supported
        UINT64 X64ApicWriteDfrExitTrap    : 1; // WHvRunVpExitReasonX64ApicWriteTrap supported
#else
        UINT64 ReservedArm2               : 2;
#endif
        UINT64 GpaAccessFaultExit         : 1; // WHvRunVpExitReasonMemoryAccess supported for second-level page faults
        UINT64 Reserved                   : 49;
    };

    UINT64 AsUINT64;
} WHV_EXTENDED_VM_EXITS;

C_ASSERT(sizeof(WHV_EXTENDED_VM_EXITS) == 8);

//
// Return values for WhvCapabilityCodeProcessorVendor
//
typedef enum WHV_PROCESSOR_VENDOR
{
    WHvProcessorVendorAmd   = 0x0000,
    WHvProcessorVendorIntel = 0x0001,
    WHvProcessorVendorHygon = 0x0002,

    WHvProcessorVendorArm   = 0x0010,

} WHV_PROCESSOR_VENDOR;

//
// Return values for WhvCapabilityCodeProcessorFeatures and input buffer for
// WHvPartitionPropertyCodeProcessorFeatures. Additionally the value is embeded
// in WHV_PROCESSOR_FEATURES_BANKS.
//

#if defined(_AMD64_)

typedef union WHV_X64_PROCESSOR_FEATURES
{
    struct
    {
        UINT64 Sse3Support : 1;
        UINT64 LahfSahfSupport : 1;
        UINT64 Ssse3Support : 1;
        UINT64 Sse4_1Support : 1;
        UINT64 Sse4_2Support : 1;
        UINT64 Sse4aSupport : 1;
        UINT64 XopSupport : 1;
        UINT64 PopCntSupport : 1;
        UINT64 Cmpxchg16bSupport : 1;
        UINT64 Altmovcr8Support : 1;
        UINT64 LzcntSupport : 1;
        UINT64 MisAlignSseSupport : 1;
        UINT64 MmxExtSupport : 1;
        UINT64 Amd3DNowSupport : 1;
        UINT64 ExtendedAmd3DNowSupport : 1;
        UINT64 Page1GbSupport : 1;
        UINT64 AesSupport : 1;
        UINT64 PclmulqdqSupport : 1;
        UINT64 PcidSupport : 1;
        UINT64 Fma4Support : 1;
        UINT64 F16CSupport : 1;
        UINT64 RdRandSupport : 1;
        UINT64 RdWrFsGsSupport : 1;
        UINT64 SmepSupport : 1;
        UINT64 EnhancedFastStringSupport : 1;
        UINT64 Bmi1Support : 1;
        UINT64 Bmi2Support : 1;
        UINT64 Reserved1 : 2;
        UINT64 MovbeSupport : 1;
        UINT64 Npiep1Support : 1;
        UINT64 DepX87FPUSaveSupport : 1;
        UINT64 RdSeedSupport : 1;
        UINT64 AdxSupport : 1;
        UINT64 IntelPrefetchSupport : 1;
        UINT64 SmapSupport : 1;
        UINT64 HleSupport : 1;
        UINT64 RtmSupport : 1;
        UINT64 RdtscpSupport : 1;
        UINT64 ClflushoptSupport : 1;
        UINT64 ClwbSupport : 1;
        UINT64 ShaSupport : 1;
        UINT64 X87PointersSavedSupport : 1;
        UINT64 InvpcidSupport : 1;
        UINT64 IbrsSupport : 1;
        UINT64 StibpSupport : 1;
        UINT64 IbpbSupport : 1;
        UINT64 UnrestrictedGuestSupport : 1;
        UINT64 SsbdSupport : 1;
        UINT64 FastShortRepMovSupport : 1;
        UINT64 Reserved3 : 1;
        UINT64 RdclNo : 1;
        UINT64 IbrsAllSupport : 1;
        UINT64 Reserved4 : 1;
        UINT64 SsbNo : 1;
        UINT64 RsbANo : 1;
        UINT64 Reserved5 : 1;
        UINT64 RdPidSupport : 1;
        UINT64 UmipSupport : 1;
        UINT64 MdsNoSupport : 1;
        UINT64 MdClearSupport : 1;
        UINT64 TaaNoSupport : 1;
        UINT64 TsxCtrlSupport : 1;
        UINT64 Reserved6 : 1;
    };

    UINT64 AsUINT64;
} WHV_X64_PROCESSOR_FEATURES, WHV_PROCESSOR_FEATURES;

C_ASSERT(sizeof(WHV_X64_PROCESSOR_FEATURES) == 8);

//
// Return values for WhvCapabilityCodeProcessorFeaturesBanks and input buffer
// for WHvPartitionPropertyCodeProcessorFeaturesBanks. BanksCount must be populated
// before calling WHP APIs.
//
typedef union WHV_X64_PROCESSOR_FEATURES1
{
    struct
    {
        UINT64 ACountMCountSupport : 1;
        UINT64 TscInvariantSupport : 1;
        UINT64 ClZeroSupport : 1;
        UINT64 RdpruSupport : 1;
        UINT64 La57Support : 1;
        UINT64 MbecSupport : 1;
        UINT64 NestedVirtSupport : 1;
        UINT64 PsfdSupport: 1;
        UINT64 CetSsSupport : 1;
        UINT64 CetIbtSupport : 1;
        UINT64 VmxExceptionInjectSupport : 1;
        UINT64 Reserved2 : 1;
        UINT64 UmwaitTpauseSupport : 1;
        UINT64 MovdiriSupport : 1;
        UINT64 Movdir64bSupport : 1;
        UINT64 CldemoteSupport : 1;
        UINT64 SerializeSupport : 1;
        UINT64 TscDeadlineTmrSupport : 1;
        UINT64 TscAdjustSupport : 1;
        UINT64 FZLRepMovsb : 1;
        UINT64 FSRepStosb : 1;
        UINT64 FSRepCmpsb : 1;
        UINT64 TsxLdTrkSupport : 1;
        UINT64 VmxInsOutsExitInfoSupport : 1;
        UINT64 Reserved3 : 1;
        UINT64 SbdrSsdpNoSupport : 1;
        UINT64 FbsdpNoSupport : 1;
        UINT64 PsdpNoSupport : 1;
        UINT64 FbClearSupport : 1;
        UINT64 BtcNoSupport : 1;
        UINT64 IbpbRsbFlushSupport : 1;
        UINT64 StibpAlwaysOnSupport : 1;
        UINT64 PerfGlobalCtrlSupport : 1;
        UINT64 NptExecuteOnlySupport : 1;
        UINT64 NptADFlagsSupport : 1;
        UINT64 Npt1GbPageSupport : 1;
        UINT64 Reserved4 : 1;
        UINT64 Reserved5 : 1;
        UINT64 Reserved6 : 1;
        UINT64 Reserved7 : 1;
        UINT64 CmpccxaddSupport : 1;
        UINT64 Reserved8 : 1; // TscAuxVirtualization
        UINT64 Reserved9 : 1; // RmpQuery
        UINT64 Reserved10 : 1;
        UINT64 Reserved11 : 1;
        UINT64 PrefetchISupport : 1;
        UINT64 Sha512Support : 1;
        UINT64 Reserved12 : 1;
        UINT64 Reserved13 : 1;
        UINT64 Reserved14 : 1;
        UINT64 SM3Support : 1;
        UINT64 SM4Support : 1;
        UINT64 Reserved15 : 12;
    };

    UINT64 AsUINT64;
} WHV_X64_PROCESSOR_FEATURES1, WHV_PROCESSOR_FEATURES1;

C_ASSERT(sizeof(WHV_X64_PROCESSOR_FEATURES1) == 8);

#elif defined(_ARM64_)

typedef union WHV_ARM64_PROCESSOR_FEATURES
{
    struct
    {
        //
        // Bits for features reported by ID_AA64MMFR0_EL1
        //

        UINT64 Asid16:1;                    // 16 bits ASID.
        UINT64 TGran16:1;                   // Indicated support for 16KB memory translation granule.
        UINT64 TGran64:1;                   // Indicated support for 64KB memory translation granule.

        //
        // Bits for features reported by ID_AA64MMFR1_EL1
        //

        UINT64 Haf:1;                       // Hardware updates to Access flag.
        UINT64 Hdbs:1;                      // Hardware updates to Dirty state.
        UINT64 Pan:1;                       // Privileged access never (ARMv8.1).
        UINT64 AtS1E1:1;                    // AT S1E1RP and AT S1E1WP supported.

        //
        // Bits for features reported by ID_AA64MMFR2_EL1
        //

        UINT64 Uao:1;                       // PSTATE override of Unprivileged Load/Store (ARMv8.2)

        //
        // Bits for features reported by ID_AA64PFR0_EL1
        //

        UINT64 El0Aarch32:1;                // If Aarch32 is supported at El0.
        UINT64 Fp:1;                        // Floating point support.
        UINT64 FpHp:1;                      // Floating point half-precision support.
        UINT64 AdvSimd:1;                   // AdvSIMD is implemented.
        UINT64 AdvSimdHp:1;                 // AdvSIMD with half precision floating point support.
        UINT64 GicV3V4:1;                   // System register interface to versions 3 and 4 of the GIC CPU interface is implemented.
        UINT64 GicV41:1;                    // System register interface to version 4.1 of the GIC CPU interface is implemented.
        UINT64 Ras:1;                       // Ras

        //
        // Bits for features reported by ID_AA64DFR0_EL1
        //

        UINT64 PmuV3:1;                     // PMUv3 implemented.
        UINT64 PmuV3ArmV81:1;               // PMUv3 for Armv8.1 implemented.
        UINT64 PmuV3ArmV84:1;               // PMUv3 for Armv8.4 implemented.
        UINT64 PmuV3ArmV85:1;               // PMUv3 for Armv8.5 implemented.

        //
        // Bits for features reported by ID_AA64ISAR0_EL1
        //

        UINT64 Aes:1;                      // AES(AESE, AESD, AESMC, AESIMC) instructions.
        UINT64 PolyMul:1;                  // Polynomial multiply instructions PMULL/PMULL2
        UINT64 Sha1:1;                     // Sha1 instructions implemented.
        UINT64 Sha256:1;                   // Sha256 instructions implemented.
        UINT64 Sha512:1;                   // Sha512 instructions implemented.
        UINT64 Crc32:1;                    // CRC instructions implemented.
        UINT64 Atomic:1;                   // Atomic instructions implemented.
        UINT64 Rdm:1;                      // SQRDMLAH, SQRDMLSH instructions implemented.
        UINT64 Sha3:1;                     // Sha3 instructions implemented.
        UINT64 Sm3:1;                      // SM3 instructions implemented.
        UINT64 Sm4:1;                      // SM4 instructions implemented.
        UINT64 Dp:1;                       // UDOT and SDOT Dot product instructions implemented.
        UINT64 Fhm:1;                      // FMLAL and FMLSL instructions implemented.


        //
        // Bits for features reported by ID_AA64ISAR1_EL1
        //

        UINT64 DcCvap:1;                   // Clean data cache by address to point of persistence.
        UINT64 DcCvadp:1;                  // Clean data cache by address to point of deep persistence.

        //
        // Pointer authentication using QARMA algo.
        //

        UINT64 ApaBase:1;                  // HaveEnhancedPAC, HaveEnhancedPAC2 return false
        UINT64 ApaEp:1;                    // HaveEnhancedPAC -> true, HaveEnhancedPAC2 -> false.
        UINT64 ApaEp2:1;                   // HaveEnhancedPAC -> false, HaveEnhancedPAC2 -> true, HaveFPAC -> false, HaveFPACCombined -> false.
        UINT64 ApaEp2Fp:1;                 // HaveEnhancedPAC -> false, HaveEnahancedPAC2 -> true, HaveFPAC -> true, HaveFPACCombined -> false.
        UINT64 ApaEp2Fpc:1;                // HaveEnhancedPAC -> false, HaveEnahancedPAC2 -> true, HaveFPAC -> true, HaveFPACCombined -> true.

        UINT64 Jscvt:1;                    // FJCVTZS instruction implemented. Support for JS conversion from double to integer.
        UINT64 Fcma:1;                     // Complex number instructions(FCMLA and FCADD) instructions are implemented.
        UINT64 RcpcV83:1;                  // ARMv8.3-RCPC. LDAPR* instructions.
        UINT64 RcpcV84:1;                  // ARMv8.4-RCPC. LDAPUR* and STLUR* instructions.
        UINT64 Gpa:1;                      // Generic code authentication using QARMA algo.

        //
        // Features reported by CTR_EL0
        //

        UINT64 L1ipPipt:1;                 // If L1 Instruction cache is PIPT.

        //
        // Features reported by DCZID_EL0
        //

        UINT64 DzPermitted:1;             // Data zero instructions permitted.

        UINT64 Reserved:17;
    };

    UINT64 AsUINT64;
} WHV_ARM64_PROCESSOR_FEATURES, WHV_PROCESSOR_FEATURES;

typedef union WHV_ARM64_PROCESSOR_FEATURES1
{
    struct
    {
        UINT64 Reserved:64;
    };

    UINT64 AsUINT64;
} WHV_ARM64_PROCESSOR_FEATURES1, WHV_PROCESSOR_FEATURES1;

#endif

#define WHV_PROCESSOR_FEATURES_BANKS_COUNT 2

typedef struct WHV_PROCESSOR_FEATURES_BANKS
{
    UINT32 BanksCount;
    UINT32 Reserved0;
    union
    {
        struct
        {
            WHV_PROCESSOR_FEATURES Bank0;
            WHV_PROCESSOR_FEATURES1 Bank1;
        };

        UINT64 AsUINT64[WHV_PROCESSOR_FEATURES_BANKS_COUNT];
    };
} WHV_PROCESSOR_FEATURES_BANKS;

C_ASSERT(sizeof(WHV_PROCESSOR_FEATURES_BANKS) == 8 * (WHV_PROCESSOR_FEATURES_BANKS_COUNT + 1));

//
// Synthetic processor features for exo partitions.
//

typedef union WHV_SYNTHETIC_PROCESSOR_FEATURES
{
    struct
    {
        // Report a hypervisor is present. CPUID leaves
        // 0x40000000 and 0x40000001 are supported.
        UINT64 HypervisorPresent:1;

        //
        // Features associated with HV#1:
        //

        // Report support for Hv1 (CPUID leaves 0x40000000 - 0x40000006).
        UINT64 Hv1:1;

        // Access to HV_X64_MSR_VP_RUNTIME.
        // Corresponds to AccessVpRunTimeReg privilege.
        UINT64 AccessVpRunTimeReg:1;

        // Access to HV_X64_MSR_TIME_REF_COUNT.
        // Corresponds to AccessPartitionReferenceCounter privilege.
        UINT64 AccessPartitionReferenceCounter:1;

        // Access to SINT-related registers (HV_X64_MSR_SCONTROL through
        // HV_X64_MSR_EOM and HV_X64_MSR_SINT0 through HV_X64_MSR_SINT15).
        // Corresponds to AccessSynicRegs privilege.
        UINT64 AccessSynicRegs:1;

        // Access to synthetic timers and associated MSRs
        // (HV_X64_MSR_STIMER0_CONFIG through HV_X64_MSR_STIMER3_COUNT).
        // Corresponds to AccessSyntheticTimerRegs privilege.
        UINT64 AccessSyntheticTimerRegs:1;

        // On AMD64 and ARM64, access to the the VP assist page.  On AMD64, also
        // access to APIC MSRs (HV_X64_MSR_EOI, HV_X64_MSR_ICR and HV_X64_MSR_TPR)
        // Corresponds to AccessIntrCtrlRegs privilege.
        UINT64 AccessIntrCtrlRegs:1;

        // Access to registers associated with hypercalls (HV_X64_MSR_GUEST_OS_ID
        // and HV_X64_MSR_HYPERCALL).
        // Corresponds to AccessHypercallMsrs privilege.
        UINT64 AccessHypercallRegs:1;

        // VP index can be queried. Corresponds to AccessVpIndex privilege.
        UINT64 AccessVpIndex:1;

        // Access to the reference TSC. Corresponds to AccessPartitionReferenceTsc
        // privilege.
        UINT64 AccessPartitionReferenceTsc:1;

#if defined(_AMD64_)
        // Partition has access to the guest idle reg. Corresponds to
        // AccessGuestIdleReg privilege.
        //
        UINT64 AccessGuestIdleReg:1;

        // Partition has access to frequency regs. Corresponds to AccessFrequencyRegs
        // privilege.
        UINT64 AccessFrequencyRegs:1;
#else
        UINT64 ReservedZ10:1;
        UINT64 ReservedZ11:1;
#endif

        UINT64 ReservedZ12:1;
        UINT64 ReservedZ13:1;
        UINT64 ReservedZ14:1;

#if defined(_AMD64_)
        // Extended GVA ranges for HvCallFlushVirtualAddressList hypercall.
        // Corresponds to privilege.
        UINT64 EnableExtendedGvaRangesForFlushVirtualAddressList:1;
#else
        UINT64 ReservedZ15:1;
#endif

        UINT64 ReservedZ16:1;
        UINT64 ReservedZ17:1;

        // Use fast hypercall output. Corresponds to privilege.
        UINT64 FastHypercallOutput:1;

        UINT64 ReservedZ19:1;

        UINT64 ReservedZ20:1;

        UINT64 ReservedZ21:1;

        // Synthetic timers in direct mode.
        UINT64 DirectSyntheticTimers:1;

        UINT64 ReservedZ23:1;

        // Use extended processor masks.
        UINT64 ExtendedProcessorMasks:1;

#if defined(_AMD64_)
        // HvCallFlushVirtualAddressSpace / HvCallFlushVirtualAddressList are supported.
        UINT64 TbFlushHypercalls:1;
#else
        UINT64 ReservedZ25:1;
#endif

        // HvCallSendSyntheticClusterIpi is supported.
        UINT64 SyntheticClusterIpi:1;

        // HvCallNotifyLongSpinWait is supported.
        UINT64 NotifyLongSpinWait:1;

        // HvCallQueryNumaDistance is supported.
        UINT64 QueryNumaDistance:1;

        // HvCallSignalEvent is supported. Corresponds to privilege.
        UINT64 SignalEvents:1;

        // HvCallRetargetDeviceInterrupt is supported.
        UINT64 RetargetDeviceInterrupt:1;

#if defined(_AMD64_)
        // HvCallRestorePartitionTime is supported.
        UINT64 RestoreTime:1;

        // EnlightenedVmcs nested enlightenment is supported.
        UINT64 EnlightenedVmcs:1;

        // Non-zero values can be written to DEBUG_CTL.
        UINT64 NestedDebugCtl:1;

        // Synthetic time-unhalted timer MSRs are supported.
        UINT64 SyntheticTimeUnhaltedTimer : 1;

        // SPEC_CTRL MSR behavior when the VP is idle
        UINT64 IdleSpecCtrl:1;
#else
        UINT64 ReservedZ31:1;
        UINT64 ReservedZ32:1;
        UINT64 ReservedZ33:1;
        UINT64 ReservedZ34:1;
        UINT64 ReservedZ35:1;
#endif
        // Register intercepts are not supported.
        UINT64 ReservedZ36 : 1;
        UINT64 WakeVps:1;
        UINT64 AccessVpRegs : 1;

#if defined(_ARM64_)
        // HvCallSyncContext / HvCallSyncContextEx are supported.
        UINT64 SyncContext : 1;
#else
        UINT64 ReservedZ39 : 1;
#endif

        UINT64 ReservedZ40 : 1;

        UINT64 Reserved:23;
    };

    UINT64 AsUINT64;
} WHV_SYNTHETIC_PROCESSOR_FEATURES;

C_ASSERT(sizeof(WHV_SYNTHETIC_PROCESSOR_FEATURES) == 8);

#define WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS_COUNT 1

typedef struct WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS
{
    UINT32 BanksCount;
    UINT32 Reserved0;
    union
    {
        struct
        {
            WHV_SYNTHETIC_PROCESSOR_FEATURES Bank0;
        };

        UINT64 AsUINT64[WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS_COUNT];
    };
} WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS;

C_ASSERT(sizeof(WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS) == 16);

//
// Virtual trust level (VTL)
//

typedef UINT8 WHV_VTL;

//
// Input for targeting a specific VTL.
//

typedef union WHV_INPUT_VTL
{
    UINT8 AsUINT8;
    struct
    {
        UINT8 TargetVtl    : 4;
        UINT8 UseTargetVtl : 1;
        UINT8 Reserved     : 3;
    };
} WHV_INPUT_VTL;

//
// Input for enabling patition VTL
//

typedef union WHV_ENABLE_PARTITION_VTL_FLAGS
{
    UINT8 AsUINT8;
    struct
    {
        UINT8 EnableMbec:1;
        UINT8 EnableSupervisorShadowStack:1;
        UINT8 EnableHardwareHvpt:1;
        UINT8 Reserved:5;
    };
} WHV_ENABLE_PARTITION_VTL_FLAGS;

//
// Input for disabling patition VTL
//

typedef union WHV_DISABLE_PARTITION_VTL_FLAGS
{
    UINT8 AsUINT8;
    struct
    {
        UINT8 ScrubOnly:1;
        UINT8 Reserved:7;
    };
} WHV_DISABLE_PARTITION_VTL_FLAGS;

//
// Initial VP context for enabling VP VTL
//

typedef struct WHV_INITIAL_VP_CONTEXT
{

#if defined(_ARM64_)

    UINT64 Pc;
    UINT64 Sp_ELh;
    UINT64 SCTLR_EL1;
    UINT64 MAIR_EL1;
    UINT64 TCR_EL1;
    UINT64 VBAR_EL1;
    UINT64 TTBR0_EL1;
    UINT64 TTBR1_EL1;
    UINT64 X18;

#else

    UINT64 Rip;
    UINT64 Rsp;
    UINT64 Rflags;

    //
    // Segment selector registers together with their hidden state.
    //

    WHV_X64_SEGMENT_REGISTER Cs;
    WHV_X64_SEGMENT_REGISTER Ds;
    WHV_X64_SEGMENT_REGISTER Es;
    WHV_X64_SEGMENT_REGISTER Fs;
    WHV_X64_SEGMENT_REGISTER Gs;
    WHV_X64_SEGMENT_REGISTER Ss;
    WHV_X64_SEGMENT_REGISTER Tr;
    WHV_X64_SEGMENT_REGISTER Ldtr;

    //
    // Global and Interrupt Descriptor tables
    //

    WHV_X64_TABLE_REGISTER Idtr;
    WHV_X64_TABLE_REGISTER Gdtr;

    //
    // Control registers and MSR's
    //

    UINT64 Efer;
    UINT64 Cr0;
    UINT64 Cr3;
    UINT64 Cr4;
    UINT64 MsrCrPat;

#endif

} WHV_INITIAL_VP_CONTEXT;

//
// Input for disabling VP VTL
//

typedef union WHV_DISABLE_VP_VTL_FLAGS
{
    UINT8 AsUINT8;
    struct
    {
        UINT8 ScrubOnly:1;
        UINT8 Reserved:7;
    };
} WHV_DISABLE_VP_VTL_FLAGS;

//
// Partitions
//

typedef VOID* WHV_PARTITION_HANDLE;

typedef enum WHV_PARTITION_PROPERTY_CODE
{
    WHvPartitionPropertyCodeExtendedVmExits         = 0x00000001,
#if defined(_AMD64_)
    WHvPartitionPropertyCodeExceptionExitBitmap     = 0x00000002,
#endif
    WHvPartitionPropertyCodeSeparateSecurityDomain  = 0x00000003,
    WHvPartitionPropertyCodeNestedVirtualization    = 0x00000004,
#if defined(_AMD64_)
    WHvPartitionPropertyCodeX64MsrExitBitmap        = 0x00000005,
#endif
    WHvPartitionPropertyCodePrimaryNumaNode         = 0x00000006,
    WHvPartitionPropertyCodeCpuReserve              = 0x00000007,
    WHvPartitionPropertyCodeCpuCap                  = 0x00000008,
    WHvPartitionPropertyCodeCpuWeight               = 0x00000009,
    WHvPartitionPropertyCodeCpuGroupId              = 0x0000000a,
    WHvPartitionPropertyCodeProcessorFrequencyCap   = 0x0000000b,
    WHvPartitionPropertyCodeAllowDeviceAssignment   = 0x0000000c,
    WHvPartitionPropertyCodeDisableSmt              = 0x0000000d,

    WHvPartitionPropertyCodeProcessorFeatures               = 0x00001001,
    WHvPartitionPropertyCodeProcessorClFlushSize            = 0x00001002,
#if defined(_AMD64_)
    WHvPartitionPropertyCodeCpuidExitList                   = 0x00001003,
    WHvPartitionPropertyCodeCpuidResultList                 = 0x00001004,
    WHvPartitionPropertyCodeLocalApicEmulationMode          = 0x00001005,
    WHvPartitionPropertyCodeProcessorXsaveFeatures          = 0x00001006,
#endif
    WHvPartitionPropertyCodeProcessorClockFrequency         = 0x00001007,
#if defined(_AMD64_)
    WHvPartitionPropertyCodeInterruptClockFrequency         = 0x00001008,
    WHvPartitionPropertyCodeApicRemoteReadSupport           = 0x00001009,
#endif
    WHvPartitionPropertyCodeProcessorFeaturesBanks          = 0x0000100A,
    WHvPartitionPropertyCodeReferenceTime                   = 0x0000100B,
    WHvPartitionPropertyCodeSyntheticProcessorFeaturesBanks = 0x0000100C,
#if defined(_AMD64_)
    WHvPartitionPropertyCodeCpuidResultList2                = 0x0000100D,
    WHvPartitionPropertyCodeProcessorPerfmonFeatures        = 0x0000100E,
    WHvPartitionPropertyCodeMsrActionList                   = 0x0000100F,
    WHvPartitionPropertyCodeUnimplementedMsrAction          = 0x00001010,
#endif
    WHvPartitionPropertyCodePhysicalAddressWidth            = 0x00001011,
    WHvPartitionPropertyCodeProcessorCount          = 0x00001fff
} WHV_PARTITION_PROPERTY_CODE;

#if defined(_AMD64_)

//
// Return values for WHvCapabilityCodeProcessorXsaveFeatures and input buffer
// for WHvPartitionPropertyCodeProcessorXsaveFeatures
//
typedef union WHV_PROCESSOR_XSAVE_FEATURES
{
    struct
    {
        UINT64 XsaveSupport : 1;
        UINT64 XsaveoptSupport : 1;
        UINT64 AvxSupport : 1;
        UINT64 Avx2Support : 1;
        UINT64 FmaSupport : 1;
        UINT64 MpxSupport : 1;
        UINT64 Avx512Support : 1;
        UINT64 Avx512DQSupport : 1;
        UINT64 Avx512CDSupport : 1;
        UINT64 Avx512BWSupport : 1;
        UINT64 Avx512VLSupport : 1;
        UINT64 XsaveCompSupport : 1;
        UINT64 XsaveSupervisorSupport : 1;
        UINT64 Xcr1Support : 1;
        UINT64 Avx512BitalgSupport : 1;
        UINT64 Avx512IfmaSupport : 1;
        UINT64 Avx512VBmiSupport : 1;
        UINT64 Avx512VBmi2Support : 1;
        UINT64 Avx512VnniSupport : 1;
        UINT64 GfniSupport : 1;
        UINT64 VaesSupport : 1;
        UINT64 Avx512VPopcntdqSupport : 1;
        UINT64 VpclmulqdqSupport : 1;
        UINT64 Avx512Bf16Support : 1;
        UINT64 Avx512Vp2IntersectSupport : 1;
        UINT64 Avx512Fp16Support : 1;
        UINT64 XfdSupport : 1;
        UINT64 AmxTileSupport : 1;
        UINT64 AmxBf16Support : 1;
        UINT64 AmxInt8Support : 1;
        UINT64 AvxVnniSupport : 1;
        UINT64 AvxIfmaSupport : 1;
        UINT64 AvxNeConvertSupport : 1;
        UINT64 AvxVnniInt8Support : 1;
        UINT64 AvxVnniInt16Support : 1;
        UINT64 Avx10_1_256Support : 1;
        UINT64 Avx10_1_512Support : 1;
        UINT64 AmxFp16Support : 1;
        UINT64 Reserved : 26;
    };

    UINT64 AsUINT64;
} WHV_PROCESSOR_XSAVE_FEATURES, *PWHV_PROCESSOR_XSAVE_FEATURES;

C_ASSERT(sizeof(WHV_PROCESSOR_XSAVE_FEATURES) == 8);

//
// Return values for WHvCapabilityCodeProcessorPerfmonFeatures and input buffer
// for WHvPartitionPropertyCodeProcessorPerfmonFeatures
//
typedef union WHV_PROCESSOR_PERFMON_FEATURES
{
    struct
    {
        UINT64 PmuSupport : 1;
        UINT64 LbrSupport : 1;
        UINT64 Reserved : 62;
    };

    UINT64 AsUINT64;
} WHV_PROCESSOR_PERFMON_FEATURES, *PWHV_PROCESSOR_PERFMON_FEATURES;

C_ASSERT(sizeof(WHV_PROCESSOR_PERFMON_FEATURES) == 8);

//
// Return value for WHvCapabilityCodeX64MsrExits and input buffer for
// WHvPartitionPropertyCodeX64MsrcExits
//
typedef union WHV_X64_MSR_EXIT_BITMAP
{
    UINT64 AsUINT64;
    struct
    {
        UINT64 UnhandledMsrs:1;
        UINT64 TscMsrWrite:1;
        UINT64 TscMsrRead:1;
        UINT64 ApicBaseMsrWrite:1;
        UINT64 MiscEnableMsrRead:1;
        UINT64 McUpdatePatchLevelMsrRead:1;
        UINT64 Reserved:58;
    };

} WHV_X64_MSR_EXIT_BITMAP;

C_ASSERT(sizeof(WHV_X64_MSR_EXIT_BITMAP) == 8);

#endif // defined(_AMD64_)

//
// Memory Management
//

//
// Guest physical or virtual address
//
typedef UINT64 WHV_GUEST_PHYSICAL_ADDRESS;
typedef UINT64 WHV_GUEST_VIRTUAL_ADDRESS;

//
// Flags used by WHvMapGpaRange/WHvMapGpaRange2
//
typedef enum WHV_MAP_GPA_RANGE_FLAGS
{
    WHvMapGpaRangeFlagNone             = 0x00000000,
    WHvMapGpaRangeFlagRead             = 0x00000001,
    WHvMapGpaRangeFlagWrite            = 0x00000002,
    WHvMapGpaRangeFlagExecute          = 0x00000004,
    WHvMapGpaRangeFlagTrackDirtyPages  = 0x00000008,

} WHV_MAP_GPA_RANGE_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_MAP_GPA_RANGE_FLAGS);

//
// Flags used by WHvTranslateGva
//
typedef enum WHV_TRANSLATE_GVA_FLAGS
{
    WHvTranslateGvaFlagNone             = 0x00000000,
    WHvTranslateGvaFlagValidateRead     = 0x00000001,
    WHvTranslateGvaFlagValidateWrite    = 0x00000002,
    WHvTranslateGvaFlagValidateExecute  = 0x00000004,
#if defined(_AMD64_)
    WHvTranslateGvaFlagPrivilegeExempt  = 0x00000008,
#endif
    WHvTranslateGvaFlagSetPageTableBits = 0x00000010,
#if defined(_AMD64_)
    WHvTranslateGvaFlagEnforceSmap      = 0x00000100,
    WHvTranslateGvaFlagOverrideSmap     = 0x00000200
#endif
} WHV_TRANSLATE_GVA_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_TRANSLATE_GVA_FLAGS);

//
// Flags used by WHvTranslateGva2, extension of WHV_TRANSLATE_GVA_FLAGS
//

typedef union WHV_TRANSLATE_GVA_2_FLAGS
{
    struct
    {
        UINT64 ValidateRead     : 1;
        UINT64 ValidateWrite    : 1;
        UINT64 ValidateExecute  : 1;
#if defined(_AMD64_)
        UINT64 PrivilegeExempt  : 1;
#else
        UINT64 Reserved0        : 1;
#endif
        UINT64 SetPageTableBits : 1;
        UINT64 Reserved1        : 3;
#if defined(_AMD64_)
        UINT64 EnforceSmap      : 1;
        UINT64 OverrideSmap     : 1;
#else
        UINT64 Reserved2        : 1;
        UINT64 Reserved3        : 1;
#endif
        UINT64 Reserved4        : 46;
        UINT64 InputVtl         : 8;
    };

    UINT64 AsUINT64;
} WHV_TRANSLATE_GVA_2_FLAGS;

C_ASSERT(sizeof(WHV_TRANSLATE_GVA_2_FLAGS) == 8);

//
// Result of an attempt to translate a guest virtual address
//
typedef enum WHV_TRANSLATE_GVA_RESULT_CODE
{
    WHvTranslateGvaResultSuccess                 = 0,

    // Translation failures
    WHvTranslateGvaResultPageNotPresent          = 1,
    WHvTranslateGvaResultPrivilegeViolation      = 2,
    WHvTranslateGvaResultInvalidPageTableFlags   = 3,

    // GPA access failures
    WHvTranslateGvaResultGpaUnmapped             = 4,
    WHvTranslateGvaResultGpaNoReadAccess         = 5,
    WHvTranslateGvaResultGpaNoWriteAccess        = 6,
    WHvTranslateGvaResultGpaIllegalOverlayAccess = 7,
    WHvTranslateGvaResultIntercept               = 8
} WHV_TRANSLATE_GVA_RESULT_CODE;

//
// Output buffer of WHvTranslateGva
//
typedef struct WHV_TRANSLATE_GVA_RESULT
{
    WHV_TRANSLATE_GVA_RESULT_CODE ResultCode;
    UINT32 Reserved;
} WHV_TRANSLATE_GVA_RESULT;

C_ASSERT(sizeof(WHV_TRANSLATE_GVA_RESULT) == 8);

//
// Maxmium data size used by WHvReadGpaRange and WHvWriteGpaRange
//
#define WHV_READ_WRITE_GPA_RANGE_MAX_SIZE 16

//
// Structure describing a memory range entry
//
typedef struct WHV_MEMORY_RANGE_ENTRY {
    UINT64 GuestAddress;
    UINT64 SizeInBytes;
} WHV_MEMORY_RANGE_ENTRY;

C_ASSERT(sizeof(WHV_MEMORY_RANGE_ENTRY) == 16);

typedef union WHV_ADVISE_GPA_RANGE_POPULATE_FLAGS
{
    UINT32 AsUINT32;
    struct
    {
        UINT32 Prefetch:1;
        UINT32 AvoidHardFaults:1;
        UINT32 Reserved:30;
    };
} WHV_ADVISE_GPA_RANGE_POPULATE_FLAGS;

C_ASSERT(sizeof(WHV_ADVISE_GPA_RANGE_POPULATE_FLAGS) == 4);

typedef enum WHV_MEMORY_ACCESS_TYPE
{
    WHvMemoryAccessRead    = 0,
    WHvMemoryAccessWrite   = 1,
    WHvMemoryAccessExecute = 2
} WHV_MEMORY_ACCESS_TYPE;

//
// Parameters used by WHvAdviseGpaRangeCodePopulate
//
typedef struct WHV_ADVISE_GPA_RANGE_POPULATE
{
    WHV_ADVISE_GPA_RANGE_POPULATE_FLAGS Flags;
    WHV_MEMORY_ACCESS_TYPE AccessType;
} WHV_ADVISE_GPA_RANGE_POPULATE;

C_ASSERT(sizeof(WHV_ADVISE_GPA_RANGE_POPULATE) == 8);

//
// WHvAdviseGpaRange buffer
//
typedef union WHV_ADVISE_GPA_RANGE
{
    WHV_ADVISE_GPA_RANGE_POPULATE Populate;
} WHV_ADVISE_GPA_RANGE;

C_ASSERT(sizeof(WHV_ADVISE_GPA_RANGE) == 8);

typedef enum WHV_CACHE_TYPE {
    WHvCacheTypeUncached         = 0,
    WHvCacheTypeWriteCombining   = 1,
    WHvCacheTypeWriteThrough     = 4,

#if defined(_AMD64_)
    WHvCacheTypeWriteProtected   = 5,
#endif

    WHvCacheTypeWriteBack        = 6
} WHV_CACHE_TYPE;

//
// Control flags used by WHvReadGpaRange and WHvWriteGpaRange
//
typedef union WHV_ACCESS_GPA_CONTROLS
{
    UINT64 AsUINT64;
    struct
    {
        //
        // Cache type for access
        //
        WHV_CACHE_TYPE CacheType;

        //
        // VTL whose GPA is to be accessed
        //
        WHV_INPUT_VTL InputVtl;
        UINT8 Reserved;
        UINT16 Reserved1;
    };
} WHV_ACCESS_GPA_CONTROLS;

C_ASSERT(sizeof(WHV_ACCESS_GPA_CONTROLS) == 8);

typedef struct WHV_CAPABILITY_PROCESSOR_FREQUENCY_CAP
{
    UINT32 IsSupported:1;
    UINT32 Reserved:31;
    UINT32 HighestFrequencyMhz;
    UINT32 NominalFrequencyMhz;
    UINT32 LowestFrequencyMhz;
    UINT32 FrequencyStepMhz;
} WHV_CAPABILITY_PROCESSOR_FREQUENCY_CAP;

C_ASSERT(sizeof(WHV_CAPABILITY_PROCESSOR_FREQUENCY_CAP) == 20);

typedef union WHV_SCHEDULER_FEATURES
{
    struct
    {
        UINT64 CpuReserve: 1;
        UINT64 CpuCap: 1;
        UINT64 CpuWeight: 1;
        UINT64 CpuGroupId: 1;
        UINT64 DisableSmt: 1;
        UINT64 Reserved: 59;
    };

    UINT64 AsUINT64;
} WHV_SCHEDULER_FEATURES;

C_ASSERT(sizeof(WHV_SCHEDULER_FEATURES) == 8);

//
// WHvGetCapability output buffer
//
typedef union WHV_CAPABILITY
{
    BOOL HypervisorPresent;
    WHV_CAPABILITY_FEATURES Features;
    WHV_EXTENDED_VM_EXITS ExtendedVmExits;
    WHV_PROCESSOR_VENDOR ProcessorVendor;
    WHV_PROCESSOR_FEATURES ProcessorFeatures;
    WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS SyntheticProcessorFeaturesBanks;
    UINT8 ProcessorClFlushSize;
    UINT64 ProcessorClockFrequency;
    WHV_PROCESSOR_FEATURES_BANKS ProcessorFeaturesBanks;
    WHV_ADVISE_GPA_RANGE_POPULATE_FLAGS GpaRangePopulateFlags;
    WHV_CAPABILITY_PROCESSOR_FREQUENCY_CAP ProcessorFrequencyCap;
    WHV_SCHEDULER_FEATURES SchedulerFeatures;
    UINT32 PhysicalAddressWidth;
    UINT64 NestedFeatureRegister;
#if defined(_AMD64_)
    WHV_PROCESSOR_XSAVE_FEATURES ProcessorXsaveFeatures;
    UINT64 InterruptClockFrequency;
    WHV_PROCESSOR_PERFMON_FEATURES ProcessorPerfmonFeatures;
    WHV_X64_MSR_EXIT_BITMAP X64MsrExitBitmap;
    UINT64 ExceptionExitBitmap;
#endif
} WHV_CAPABILITY;

#if defined(_AMD64_)

//
// WHvPartitionPropertyCodeCpuidResultList input buffer list element.
//
typedef struct WHV_X64_CPUID_RESULT
{
    UINT32 Function;
    UINT32 Reserved[3];
    UINT32 Eax;
    UINT32 Ebx;
    UINT32 Ecx;
    UINT32 Edx;
} WHV_X64_CPUID_RESULT;

C_ASSERT(sizeof(WHV_X64_CPUID_RESULT) == 32);

typedef enum WHV_X64_CPUID_RESULT2_FLAGS
{
    WHvX64CpuidResult2FlagSubleafSpecific   = 0x00000001,
    WHvX64CpuidResult2FlagVpSpecific        = 0x00000002,
} WHV_X64_CPUID_RESULT2_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_X64_CPUID_RESULT2_FLAGS);

typedef struct WHV_CPUID_OUTPUT
{
    UINT32 Eax;
    UINT32 Ebx;
    UINT32 Ecx;
    UINT32 Edx;
} WHV_CPUID_OUTPUT;

C_ASSERT(sizeof(WHV_CPUID_OUTPUT) == 16);

//
// WHvPartitionPropertyCodeCpuidResultList2 input buffer list element.
//
typedef struct WHV_X64_CPUID_RESULT2
{
    UINT32 Function;
    UINT32 Index;
    UINT32 VpIndex;
    WHV_X64_CPUID_RESULT2_FLAGS Flags;
    WHV_CPUID_OUTPUT Output;
    WHV_CPUID_OUTPUT Mask;
} WHV_X64_CPUID_RESULT2;

C_ASSERT(sizeof(WHV_X64_CPUID_RESULT2) == 48);

//
// WHvPartitionPropertyCodeMsrActionList input buffer list element.
//
typedef struct WHV_MSR_ACTION_ENTRY
{
    UINT32 Index;
    UINT8 ReadAction; // WHV_MSR_ACTION
    UINT8 WriteAction; // WHV_MSR_ACTION
    UINT16 Reserved;
} WHV_MSR_ACTION_ENTRY;

C_ASSERT(sizeof(WHV_MSR_ACTION_ENTRY) == 8);

//
// WHvPartitionPropertyCodeUnimplementedMsrAction input.
//
typedef enum WHV_MSR_ACTION
{
    WHvMsrActionArchitectureDefault = 0,
    WHvMsrActionIgnoreWriteReadZero = 1,
    WHvMsrActionExit = 2,
} WHV_MSR_ACTION;

//
// WHvPartitionPropertyCodeExceptionBitmap enumeration values.
//
typedef enum WHV_EXCEPTION_TYPE
{
    WHvX64ExceptionTypeDivideErrorFault = 0x0,
    WHvX64ExceptionTypeDebugTrapOrFault = 0x1,
    WHvX64ExceptionTypeBreakpointTrap = 0x3,
    WHvX64ExceptionTypeOverflowTrap = 0x4,
    WHvX64ExceptionTypeBoundRangeFault = 0x5,
    WHvX64ExceptionTypeInvalidOpcodeFault = 0x6,
    WHvX64ExceptionTypeDeviceNotAvailableFault = 0x7,
    WHvX64ExceptionTypeDoubleFaultAbort = 0x8,
    WHvX64ExceptionTypeInvalidTaskStateSegmentFault = 0x0A,
    WHvX64ExceptionTypeSegmentNotPresentFault = 0x0B,
    WHvX64ExceptionTypeStackFault = 0x0C,
    WHvX64ExceptionTypeGeneralProtectionFault = 0x0D,
    WHvX64ExceptionTypePageFault = 0x0E,
    WHvX64ExceptionTypeFloatingPointErrorFault = 0x10,
    WHvX64ExceptionTypeAlignmentCheckFault = 0x11,
    WHvX64ExceptionTypeMachineCheckAbort = 0x12,
    WHvX64ExceptionTypeSimdFloatingPointFault = 0x13,
} WHV_EXCEPTION_TYPE;

typedef enum WHV_X64_LOCAL_APIC_EMULATION_MODE
{
    WHvX64LocalApicEmulationModeNone,
    WHvX64LocalApicEmulationModeXApic,
    WHvX64LocalApicEmulationModeX2Apic
} WHV_X64_LOCAL_APIC_EMULATION_MODE;

#endif // defined(_AMD64_)

//
// WHvGetPartitionProperty output buffer / WHvSetPartitionProperty input buffer
//
typedef union WHV_PARTITION_PROPERTY
{
    WHV_EXTENDED_VM_EXITS ExtendedVmExits;
    WHV_PROCESSOR_FEATURES ProcessorFeatures;
    WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS SyntheticProcessorFeaturesBanks;
    UINT8 ProcessorClFlushSize;
    UINT32 ProcessorCount;
    BOOL SeparateSecurityDomain;
    BOOL NestedVirtualization;
    UINT64 ProcessorClockFrequency;
    WHV_PROCESSOR_FEATURES_BANKS ProcessorFeaturesBanks;
    UINT64 ReferenceTime;
    USHORT PrimaryNumaNode;
    UINT32 CpuReserve;
    UINT32 CpuCap;
    UINT32 CpuWeight;
    UINT64 CpuGroupId;
    UINT32 ProcessorFrequencyCap;
    BOOL AllowDeviceAssignment;
    BOOL DisableSmt;
    UINT32 PhysicalAddressWidth;
#if defined(_AMD64_)
    WHV_PROCESSOR_XSAVE_FEATURES ProcessorXsaveFeatures;
    UINT32 CpuidExitList[1];
    UINT64 ExceptionExitBitmap;
    BOOL ApicRemoteRead;
    WHV_X64_MSR_EXIT_BITMAP X64MsrExitBitmap;
    WHV_PROCESSOR_PERFMON_FEATURES ProcessorPerfmonFeatures;
    UINT64 InterruptClockFrequency;
    WHV_X64_CPUID_RESULT CpuidResultList[1];
    WHV_X64_CPUID_RESULT2 CpuidResultList2[1];
    WHV_MSR_ACTION_ENTRY MsrActionList[1];
    WHV_MSR_ACTION UnimplementedMsrAction;
    WHV_X64_LOCAL_APIC_EMULATION_MODE LocalApicEmulationMode;
#endif
} WHV_PARTITION_PROPERTY;

//
// Virtual Processor Execution
//

//
// Reason for a VM exit
//

#if defined(_AMD64_)

typedef enum WHV_RUN_VP_EXIT_REASON
{
    WHvRunVpExitReasonNone                   = 0x00000000,

    // Standard exits caused by operations of the virtual processor
    WHvRunVpExitReasonMemoryAccess           = 0x00000001,
    WHvRunVpExitReasonX64IoPortAccess        = 0x00000002,
    WHvRunVpExitReasonUnrecoverableException = 0x00000004,
    WHvRunVpExitReasonInvalidVpRegisterValue = 0x00000005,
    WHvRunVpExitReasonUnsupportedFeature     = 0x00000006,
    WHvRunVpExitReasonX64InterruptWindow     = 0x00000007,
    WHvRunVpExitReasonX64Halt                = 0x00000008,
    WHvRunVpExitReasonX64ApicEoi             = 0x00000009,
    WHvRunVpExitReasonSynicSintDeliverable   = 0x0000000A,

    // Additional exits that can be configured through partition properties
    WHvRunVpExitReasonX64MsrAccess           = 0x00001000,
    WHvRunVpExitReasonX64Cpuid               = 0x00001001,
    WHvRunVpExitReasonException              = 0x00001002,
    WHvRunVpExitReasonX64Rdtsc               = 0x00001003,
    WHvRunVpExitReasonX64ApicSmiTrap         = 0x00001004,
    WHvRunVpExitReasonHypercall              = 0x00001005,
    WHvRunVpExitReasonX64ApicInitSipiTrap    = 0x00001006,
    WHvRunVpExitReasonX64ApicWriteTrap       = 0x00001007,

    // Exits caused by the host
    WHvRunVpExitReasonCanceled               = 0x00002001,
} WHV_RUN_VP_EXIT_REASON;

#elif defined(_ARM64_)

typedef enum WHV_RUN_VP_EXIT_REASON
{
    WHvRunVpExitReasonNone                   = 0x00000000,

    // Standard exits caused by operations of the virtual processor
    WHvRunVpExitReasonUnmappedGpa            = 0x80000000,
    WHvRunVpExitReasonGpaIntercept           = 0x80000001,
    WHvRunVpExitReasonUnrecoverableException = 0x80000021,
    WHvRunVpExitReasonInvalidVpRegisterValue = 0x80000020,
    WHvRunVpExitReasonUnsupportedFeature     = 0x80000022,
    WHvRunVpExitReasonSynicSintDeliverable   = 0x80000062,
    WHvRunVpExitReasonArm64Reset             = 0x8001000c,

    // Additional exits that can be configured through partition properties
    WHvRunVpExitReasonHypercall              = 0x80000050,

    WHvRunVpExitReasonCanceled              = 0xFFFFFFFF
} WHV_RUN_VP_EXIT_REASON;

#endif // _ARCH_

#if defined(_AMD64_)

//
// Execution state of the virtual processor
//
typedef union WHV_X64_VP_EXECUTION_STATE
{
    struct
    {
        UINT16 Cpl : 2;
        UINT16 Cr0Pe : 1;
        UINT16 Cr0Am : 1;
        UINT16 EferLma : 1;
        UINT16 DebugActive : 1;
        UINT16 InterruptionPending : 1;
        UINT16 Reserved0 : 5;
        UINT16 InterruptShadow : 1;
        UINT16 Reserved1 : 3;
    };

    UINT16 AsUINT16;
} WHV_X64_VP_EXECUTION_STATE;

C_ASSERT(sizeof(WHV_X64_VP_EXECUTION_STATE) == 2);

//
// Execution context of a virtual processor at the time of an exit
//
typedef struct WHV_X64_VP_EXIT_CONTEXT
{
    WHV_X64_VP_EXECUTION_STATE ExecutionState;
    UINT8 InstructionLength : 4;
    UINT8 Cr8 : 4;
    UINT8 Reserved;
    UINT32 Reserved2;
    WHV_X64_SEGMENT_REGISTER Cs;
    UINT64 Rip;
    UINT64 Rflags;
} WHV_X64_VP_EXIT_CONTEXT, WHV_VP_EXIT_CONTEXT;

C_ASSERT(sizeof(WHV_X64_VP_EXIT_CONTEXT) == 40);

typedef struct WHV_SYNIC_SINT_DELIVERABLE_CONTEXT
{
    UINT16 DeliverableSints;
    UINT16 Reserved1;
    UINT32 Reserved2;
} WHV_SYNIC_SINT_DELIVERABLE_CONTEXT;

C_ASSERT(sizeof(WHV_SYNIC_SINT_DELIVERABLE_CONTEXT) == 8);

//
// Context data for a VM exit caused by a memory access (WHvRunVpExitReasonMemoryAccess)
//

typedef union WHV_MEMORY_ACCESS_INFO
{
    struct {
        UINT32 AccessType  : 2;  // WHV_MEMORY_ACCESS_TYPE
        UINT32 GpaUnmapped : 1;
        UINT32 GvaValid    : 1;
        UINT32 Reserved    : 28;
    };

    UINT32 AsUINT32;
} WHV_MEMORY_ACCESS_INFO;

C_ASSERT(sizeof(WHV_MEMORY_ACCESS_INFO) == 4);

typedef struct WHV_MEMORY_ACCESS_CONTEXT
{
    // Context of the virtual processor
    UINT8 InstructionByteCount;
    UINT8 Reserved[3];
    UINT8 InstructionBytes[16];

    // Memory access info
    WHV_MEMORY_ACCESS_INFO AccessInfo;
    WHV_GUEST_PHYSICAL_ADDRESS Gpa;
    WHV_GUEST_VIRTUAL_ADDRESS Gva;

} WHV_MEMORY_ACCESS_CONTEXT;


C_ASSERT(sizeof(WHV_MEMORY_ACCESS_CONTEXT) == 40);

//
// Context data for an exit caused by an I/O port access (WHvRunVpExitReasonX64IOPortAccess)
//
typedef union WHV_X64_IO_PORT_ACCESS_INFO
{
    struct
    {
        UINT32 IsWrite : 1;
        UINT32 AccessSize: 3;
        UINT32 StringOp : 1;
        UINT32 RepPrefix : 1;
        UINT32 Reserved : 26;
    };

    UINT32 AsUINT32;
} WHV_X64_IO_PORT_ACCESS_INFO;

C_ASSERT(sizeof(WHV_X64_IO_PORT_ACCESS_INFO) == 4);

typedef struct WHV_X64_IO_PORT_ACCESS_CONTEXT
{
    // Context of the virtual processor
    UINT8 InstructionByteCount;
    UINT8 Reserved[3];
    UINT8 InstructionBytes[16];

    // I/O port access info
    WHV_X64_IO_PORT_ACCESS_INFO AccessInfo;
    UINT16 PortNumber;
    UINT16 Reserved2[3];
    UINT64 Rax;
    UINT64 Rcx;
    UINT64 Rsi;
    UINT64 Rdi;
    WHV_X64_SEGMENT_REGISTER Ds;
    WHV_X64_SEGMENT_REGISTER Es;
} WHV_X64_IO_PORT_ACCESS_CONTEXT;

C_ASSERT(sizeof(WHV_X64_IO_PORT_ACCESS_CONTEXT) == 96);

//
// Context data for an exit caused by an MSR access (WHvRunVpExitReasonX64MSRAccess)
//
typedef union WHV_X64_MSR_ACCESS_INFO
{
    struct
    {
        UINT32 IsWrite : 1;
        UINT32 Reserved : 31;
    };

    UINT32 AsUINT32;
} WHV_X64_MSR_ACCESS_INFO;

C_ASSERT(sizeof(WHV_X64_MSR_ACCESS_INFO) == 4);

typedef struct WHV_X64_MSR_ACCESS_CONTEXT
{
    // MSR access info
    WHV_X64_MSR_ACCESS_INFO AccessInfo;
    UINT32 MsrNumber;
    UINT64 Rax;
    UINT64 Rdx;
} WHV_X64_MSR_ACCESS_CONTEXT;

C_ASSERT(sizeof(WHV_X64_MSR_ACCESS_CONTEXT) == 24);

//
// Context data for an exit caused by a CPUID call (WHvRunVpExitReasonX64CPUID)
//
typedef struct WHV_X64_CPUID_ACCESS_CONTEXT
{
    // CPUID access info
    UINT64 Rax;
    UINT64 Rcx;
    UINT64 Rdx;
    UINT64 Rbx;
    UINT64 DefaultResultRax;
    UINT64 DefaultResultRcx;
    UINT64 DefaultResultRdx;
    UINT64 DefaultResultRbx;
} WHV_X64_CPUID_ACCESS_CONTEXT;

C_ASSERT(sizeof(WHV_X64_CPUID_ACCESS_CONTEXT) == 64);

//
// Context data for an exit caused by an exception generated by the virtual processor
// (WHvRunVpExitReasonException)
//
typedef union WHV_VP_EXCEPTION_INFO
{
    struct
    {
        UINT32 ErrorCodeValid : 1;
        UINT32 SoftwareException : 1;
        UINT32 Reserved : 30;
    };

    UINT32 AsUINT32;
} WHV_VP_EXCEPTION_INFO;

C_ASSERT(sizeof(WHV_VP_EXCEPTION_INFO) == 4);

typedef struct WHV_VP_EXCEPTION_CONTEXT
{
    UINT8 InstructionByteCount;
    UINT8 Reserved[3];
    UINT8 InstructionBytes[16];

    // Exception info
    WHV_VP_EXCEPTION_INFO ExceptionInfo;
    UINT8 ExceptionType; // WHV_EXCEPTION_TYPE
    UINT8 Reserved2[3];
    UINT32 ErrorCode;
    UINT64 ExceptionParameter;
} WHV_VP_EXCEPTION_CONTEXT;

C_ASSERT(sizeof(WHV_VP_EXCEPTION_CONTEXT) == 40);

//
// Context data for an exit caused by the use of an unsupported processor feature
// (WHvRunVpExitReasonUnsupportedFeature)
//
typedef enum WHV_X64_UNSUPPORTED_FEATURE_CODE
{
    WHvUnsupportedFeatureIntercept     = 1,
    WHvUnsupportedFeatureTaskSwitchTss = 2
} WHV_X64_UNSUPPORTED_FEATURE_CODE;

typedef struct WHV_X64_UNSUPPORTED_FEATURE_CONTEXT
{
    WHV_X64_UNSUPPORTED_FEATURE_CODE FeatureCode;
    UINT32 Reserved;
    UINT64 FeatureParameter;
} WHV_X64_UNSUPPORTED_FEATURE_CONTEXT;

C_ASSERT(sizeof(WHV_X64_UNSUPPORTED_FEATURE_CONTEXT) == 16);

#elif defined(_ARM64_)

//
// Define virtual processor execution state bitfield.
//

typedef union WHV_VP_EXECUTION_STATE
{
    UINT16 AsUINT16;
    struct
    {
        UINT16 Cpl:2;
        UINT16 DebugActive:1;
        UINT16 InterruptionPending:1;
        UINT16 Vtl:4;
        UINT16 VirtualizationFaultActive:1;
        UINT16 Reserved:7;
    };
} WHV_VP_EXECUTION_STATE;

C_ASSERT(sizeof(WHV_VP_EXECUTION_STATE) == 2);

//
// Define intercept message header structure.
//

typedef struct WHV_INTERCEPT_MESSAGE_HEADER
{
    UINT32 VpIndex;
    UINT8 InstructionLength;
    UINT8 InterceptAccessType; // WHV_MEMORY_ACCESS_TYPE
    WHV_VP_EXECUTION_STATE ExecutionState;
    UINT64 Pc;
    UINT64 Cpsr;
} WHV_INTERCEPT_MESSAGE_HEADER;

C_ASSERT(sizeof(WHV_INTERCEPT_MESSAGE_HEADER) == 24);

typedef union WHV_MEMORY_ACCESS_INFO
{
    UINT8 AsUINT8;
    struct
    {
        UINT8 GvaValid:1;
        UINT8 GvaGpaValid:1;
        UINT8 HypercallOutputPending:1;
        UINT8 Reserved:5;
    };
} WHV_MEMORY_ACCESS_INFO;

typedef struct WHV_MEMORY_ACCESS_CONTEXT
{
    WHV_INTERCEPT_MESSAGE_HEADER Header;
    UINT32 Reserved0;
    UINT8 InstructionByteCount;
    WHV_MEMORY_ACCESS_INFO AccessInfo;
    UINT16 Reserved1;
    UINT8 InstructionBytes[4];
    UINT32 Reserved2;
    UINT64 Gva;
    UINT64 Gpa;
    UINT64 Syndrome;
} WHV_MEMORY_ACCESS_CONTEXT;

C_ASSERT(sizeof(WHV_MEMORY_ACCESS_CONTEXT) == 64);

//
// Define virtual processor unrecoverable error message.
//
typedef struct WHV_UNRECOVERABLE_EXCEPTION_CONTEXT
{
    WHV_INTERCEPT_MESSAGE_HEADER Header;
} WHV_UNRECOVERABLE_EXCEPTION_CONTEXT;

C_ASSERT(sizeof(WHV_UNRECOVERABLE_EXCEPTION_CONTEXT) == 24);

//
// Define invalid virtual processor register message.
//
typedef struct WHV_INVALID_VP_REGISTER_CONTEXT
{
    UINT32 VpIndex;
    UINT32 Reserved;
} WHV_INVALID_VP_REGISTER_CONTEXT;

C_ASSERT(sizeof(WHV_INVALID_VP_REGISTER_CONTEXT) == 8);

typedef struct WHV_SYNIC_SINT_DELIVERABLE_CONTEXT
{
    WHV_INTERCEPT_MESSAGE_HEADER Header;

    // Bitmask of deliverable SINTs.
    UINT16 DeliverableSints;

    UINT16 Reserved1;
    UINT32 Reserved2;
} WHV_SYNIC_SINT_DELIVERABLE_CONTEXT;

C_ASSERT(sizeof(WHV_SYNIC_SINT_DELIVERABLE_CONTEXT) == 32);

typedef enum WHV_ARM64_RESET_TYPE
{
    WHvArm64ResetTypePowerOff = 0,
    WHvArm64ResetTypeReboot
} WHV_ARM64_RESET_TYPE;

typedef struct WHV_ARM64_RESET_CONTEXT
{
    WHV_INTERCEPT_MESSAGE_HEADER Header;
    WHV_ARM64_RESET_TYPE ResetType;
    UINT32 Reserved;
} WHV_ARM64_RESET_CONTEXT;

C_ASSERT(sizeof(WHV_ARM64_RESET_CONTEXT) == 32);

#endif // _ARCH_

//
// Context data for an exit caused by a cancellation from the host (WHvRunVpExitReasonCanceled)
//
typedef enum WHV_RUN_VP_CANCEL_REASON
{
    WHvRunVpCancelReasonUser = 0 // Execution canceled by WHvCancelRunVirtualProcessor
} WHV_RUN_VP_CANCEL_REASON;

//
// Alias for non-standard capitalization found in earlier versions of the header
//
#define WhvRunVpCancelReasonUser WHvRunVpCancelReasonUser

typedef struct WHV_RUN_VP_CANCELED_CONTEXT
{
    WHV_RUN_VP_CANCEL_REASON CancelReason;
} WHV_RUN_VP_CANCELED_CONTEXT;

C_ASSERT(sizeof(WHV_RUN_VP_CANCELED_CONTEXT) == 4);

#if defined(_AMD64_)

//
// Context data for an exit caused by an interrupt delivery window cancellation from the host
// (WHvRunVpExitReasonX64InterruptWindow)
//
typedef enum WHV_X64_PENDING_INTERRUPTION_TYPE
{
    WHvX64PendingInterrupt           = 0,
    WHvX64PendingNmi                 = 2,
    WHvX64PendingException           = 3
} WHV_X64_PENDING_INTERRUPTION_TYPE, *PWHV_X64_PENDING_INTERRUPTION_TYPE;

typedef struct WHV_X64_INTERRUPTION_DELIVERABLE_CONTEXT
{
    WHV_X64_PENDING_INTERRUPTION_TYPE DeliverableType;
} WHV_X64_INTERRUPTION_DELIVERABLE_CONTEXT, *PWHV_X64_INTERRUPTION_DELIVERABLE_CONTEXT;

C_ASSERT(sizeof(WHV_X64_INTERRUPTION_DELIVERABLE_CONTEXT) == 4);

//
// Context data for an exit caused by an APIC EOI of a level-triggered
// interrupt (WHvRunVpExitReasonX64ApicEoi)
//
typedef struct WHV_X64_APIC_EOI_CONTEXT
{
    UINT32 InterruptVector;
} WHV_X64_APIC_EOI_CONTEXT;

C_ASSERT(sizeof(WHV_X64_APIC_EOI_CONTEXT) == 4);

//
// Context data for an exit caused by a rdtsc(p) instruction (WHvRunVpExitReasonX64Rdtsc)
//
typedef union WHV_X64_RDTSC_INFO
{
    struct
    {
        UINT64 IsRdtscp:1;
        UINT64 Reserved:63;
    };

    UINT64 AsUINT64;
} WHV_X64_RDTSC_INFO;

C_ASSERT(sizeof(WHV_X64_RDTSC_INFO) == 8);

typedef struct WHV_X64_RDTSC_CONTEXT
{
    UINT64 TscAux;
    UINT64 VirtualOffset;
    UINT64 Tsc;
    UINT64 ReferenceTime;
    WHV_X64_RDTSC_INFO RdtscInfo;
} WHV_X64_RDTSC_CONTEXT;

C_ASSERT(sizeof(WHV_X64_RDTSC_CONTEXT) == 40);

//
// Context data for an exit caused by an APIC SMI (WHvRunVpExitReasonX64ApicSmiTrap)
//
typedef struct WHV_X64_APIC_SMI_CONTEXT
{
    UINT64 ApicIcr;
} WHV_X64_APIC_SMI_CONTEXT;

C_ASSERT(sizeof(WHV_X64_APIC_SMI_CONTEXT) == 8);

#endif // defined(_AMD64_)

//
// Context data for an exit caused by a hypercall (WHvRunVpExitReasonHypercall)
//

#if defined(_AMD64_)

#define WHV_HYPERCALL_CONTEXT_MAX_XMM_REGISTERS 6

typedef struct WHV_X64_HYPERCALL_CONTEXT
{
    UINT64 Rax;
    UINT64 Rbx;
    UINT64 Rcx;
    UINT64 Rdx;
    UINT64 R8;
    UINT64 Rsi;
    UINT64 Rdi;
    UINT64 Reserved0;
    WHV_UINT128 XmmRegisters[WHV_HYPERCALL_CONTEXT_MAX_XMM_REGISTERS];
    UINT64 Reserved1[2];
} WHV_X64_HYPERCALL_CONTEXT, WHV_HYPERCALL_CONTEXT, *PWHV_HYPERCALL_CONTEXT;

C_ASSERT(sizeof(WHV_HYPERCALL_CONTEXT) == 176);

#elif defined(_ARM64_)

typedef struct WHV_ARM64_HYPERCALL_CONTEXT
{
    WHV_INTERCEPT_MESSAGE_HEADER Header;
    UINT16 Immediate;
    UINT16 Reserved1;
    UINT32 Reserved2;
    UINT64 X[18];
} WHV_ARM64_HYPERCALL_CONTEXT, WHV_HYPERCALL_CONTEXT, *PWHV_HYPERCALL_CONTEXT;

#endif

#if defined(_AMD64_)

//
// Context data for an exit caused by an APIC INIT SIPI (WHvRunVpExitReasonX64ApicInitSipiTrap)
//
typedef struct WHV_X64_APIC_INIT_SIPI_CONTEXT
{
    UINT64 ApicIcr;
} WHV_X64_APIC_INIT_SIPI_CONTEXT;

C_ASSERT(sizeof(WHV_X64_APIC_INIT_SIPI_CONTEXT) == 8);

//
// Types of APIC write exits (WHvRunVpExitReasonX64ApicWriteTrap)
//
typedef enum WHV_X64_APIC_WRITE_TYPE
{
    WHvX64ApicWriteTypeLdr   = 0xD0,
    WHvX64ApicWriteTypeDfr   = 0xE0,
    WHvX64ApicWriteTypeSvr   = 0xF0,
    WHvX64ApicWriteTypeLint0 = 0x350,
    WHvX64ApicWriteTypeLint1 = 0x360
} WHV_X64_APIC_WRITE_TYPE;

//
// Context data for an exit caused by an APIC write (WHvRunVpExitReasonX64ApicWriteTrap)
//
typedef struct WHV_X64_APIC_WRITE_CONTEXT
{
    WHV_X64_APIC_WRITE_TYPE Type;
    UINT32 Reserved;
    UINT64 WriteValue;
} WHV_X64_APIC_WRITE_CONTEXT;

C_ASSERT(sizeof(WHV_X64_APIC_WRITE_CONTEXT) == 16);

#endif // defined(_AMD64_)

// WHvRunVirtualProcessor output buffer
typedef struct WHV_RUN_VP_EXIT_CONTEXT
{
    WHV_RUN_VP_EXIT_REASON ExitReason;
    UINT32 Reserved;

#if defined(_AMD64_)
    WHV_VP_EXIT_CONTEXT VpContext;
#endif

    union
    {
        WHV_MEMORY_ACCESS_CONTEXT MemoryAccess;
        WHV_RUN_VP_CANCELED_CONTEXT CancelReason;
        WHV_HYPERCALL_CONTEXT Hypercall;
        WHV_SYNIC_SINT_DELIVERABLE_CONTEXT SynicSintDeliverable;
#if defined(_AMD64_)
        WHV_X64_IO_PORT_ACCESS_CONTEXT IoPortAccess;
        WHV_X64_MSR_ACCESS_CONTEXT MsrAccess;
        WHV_X64_CPUID_ACCESS_CONTEXT CpuidAccess;
        WHV_VP_EXCEPTION_CONTEXT VpException;
        WHV_X64_INTERRUPTION_DELIVERABLE_CONTEXT InterruptWindow;
        WHV_X64_UNSUPPORTED_FEATURE_CONTEXT UnsupportedFeature;
        WHV_X64_APIC_EOI_CONTEXT ApicEoi;
        WHV_X64_RDTSC_CONTEXT ReadTsc;
        WHV_X64_APIC_SMI_CONTEXT ApicSmi;
        WHV_X64_APIC_INIT_SIPI_CONTEXT ApicInitSipi;
        WHV_X64_APIC_WRITE_CONTEXT ApicWrite;
        UINT64 AsUINT64[22];
#elif defined(_ARM64_)
        WHV_UNRECOVERABLE_EXCEPTION_CONTEXT UnrecoverableException;
        WHV_INVALID_VP_REGISTER_CONTEXT InvalidVpRegister;
        WHV_ARM64_RESET_CONTEXT Arm64Reset;
        UINT64 AsUINT64[32];
#endif
    };
} WHV_RUN_VP_EXIT_CONTEXT;

#if defined(_AMD64_)

C_ASSERT(sizeof(WHV_RUN_VP_EXIT_CONTEXT) == 224);

#elif defined(_ARM64_)

C_ASSERT(sizeof(WHV_RUN_VP_EXIT_CONTEXT) == 264);

#endif

#if defined(_AMD64_)

typedef enum WHV_INTERRUPT_TYPE
{
    WHvX64InterruptTypeFixed            = 0,
    WHvX64InterruptTypeLowestPriority   = 1,
    WHvX64InterruptTypeNmi              = 4,
    WHvX64InterruptTypeInit             = 5,
    WHvX64InterruptTypeSipi             = 6,
    WHvX64InterruptTypeLocalInt1        = 9,
} WHV_INTERRUPT_TYPE;

typedef enum WHV_INTERRUPT_DESTINATION_MODE
{
    WHvX64InterruptDestinationModePhysical,
    WHvX64InterruptDestinationModeLogical,
} WHV_INTERRUPT_DESTINATION_MODE;

typedef enum WHV_INTERRUPT_TRIGGER_MODE
{
    WHvX64InterruptTriggerModeEdge,
    WHvX64InterruptTriggerModeLevel,
} WHV_INTERRUPT_TRIGGER_MODE;

typedef struct WHV_INTERRUPT_CONTROL
{
    UINT64 Type : 8;             // WHV_INTERRUPT_TYPE
    UINT64 DestinationMode : 4;  // WHV_INTERRUPT_DESTINATION_MODE
    UINT64 TriggerMode : 4;      // WHV_INTERRUPT_TRIGGER_MODE
    UINT64 TargetVtl : 8;        // WHV_VTL
    UINT64 Reserved : 40;
    UINT32 Destination;
    UINT32 Vector;
} WHV_INTERRUPT_CONTROL;

C_ASSERT(sizeof(WHV_INTERRUPT_CONTROL) == 16);

#elif defined(_ARM64_)

// TODO ADO (46980205) - Expose hypervisor types directly.
typedef enum WHV_INTERRUPT_TYPE
{
    WHvArm64InterruptTypeFixed             = 0x0000,

    //
    // Maximum (exclusive) value of interrupt type.
    //
    WHvArm64InterruptTypeMaximum           = 0x008,
} WHV_INTERRUPT_TYPE;

// TODO ADO (46980205) - Expose hypervisor types directly.
typedef union WHV_INTERRUPT_CONTROL2
{
    UINT64 AsUINT64;
    struct
    {
        WHV_INTERRUPT_TYPE InterruptType;
        UINT32 LevelTriggered:1;
        UINT32 LogicalDestinationMode:1;
        UINT32 Asserted:1;
        UINT32 Reserved:29;
    };
} WHV_INTERRUPT_CONTROL2;

C_ASSERT(sizeof(WHV_INTERRUPT_CONTROL2) == 8);

// TODO ADO (46980205) - Expose hypervisor types directly.
typedef struct WHV_INTERRUPT_CONTROL
{
    UINT64                  TargetPartition;
    WHV_INTERRUPT_CONTROL2  InterruptControl;
    UINT64                  DestinationAddress;
    UINT32                  RequestedVector;
    UINT8                   TargetVtl;
    UINT8                   ReservedZ0;
    UINT16                  ReservedZ1;
} WHV_INTERRUPT_CONTROL;

C_ASSERT(sizeof(WHV_INTERRUPT_CONTROL) == 32);

#endif // defined(_ARCH_)

typedef struct WHV_DOORBELL_MATCH_DATA
{
    WHV_GUEST_PHYSICAL_ADDRESS GuestAddress;
    UINT64 Value;
    UINT32 Length;
    UINT32 MatchOnValue:1;
    UINT32 MatchOnLength:1;
    UINT32 Reserved:30;
} WHV_DOORBELL_MATCH_DATA;

C_ASSERT(sizeof(WHV_DOORBELL_MATCH_DATA) == 24);

// WHvGetPartitionCounters types
typedef enum WHV_PARTITION_COUNTER_SET
{
    WHvPartitionCounterSetMemory,
} WHV_PARTITION_COUNTER_SET;

typedef struct WHV_PARTITION_MEMORY_COUNTERS
{
    UINT64 Mapped4KPageCount;
    UINT64 Mapped2MPageCount;
    UINT64 Mapped1GPageCount;
} WHV_PARTITION_MEMORY_COUNTERS;

C_ASSERT(sizeof(WHV_PARTITION_MEMORY_COUNTERS) == 24);

// WHvGetVirtualProcessorCounters types
typedef enum WHV_PROCESSOR_COUNTER_SET
{
    WHvProcessorCounterSetRuntime                   = 0,
    WHvProcessorCounterSetIntercepts                = 1,
    WHvProcessorCounterSetEvents                    = 2,
#if defined(_AMD64_)
    WHvProcessorCounterSetApic                      = 3,
#endif
    WHvProcessorCounterSetSyntheticFeatures         = 4,
} WHV_PROCESSOR_COUNTER_SET;

typedef struct WHV_PROCESSOR_RUNTIME_COUNTERS
{
    UINT64 TotalRuntime100ns;
    UINT64 HypervisorRuntime100ns;
} WHV_PROCESSOR_RUNTIME_COUNTERS;

C_ASSERT(sizeof(WHV_PROCESSOR_RUNTIME_COUNTERS) == 16);

typedef struct WHV_PROCESSOR_INTERCEPT_COUNTER
{
    UINT64 Count;
    UINT64 Time100ns;
} WHV_PROCESSOR_INTERCEPT_COUNTER;

C_ASSERT(sizeof(WHV_PROCESSOR_INTERCEPT_COUNTER) == 16);

typedef struct WHV_PROCESSOR_INTERCEPT_COUNTERS
{

#if defined(_AMD64_)

    WHV_PROCESSOR_INTERCEPT_COUNTER PageInvalidations;
    WHV_PROCESSOR_INTERCEPT_COUNTER ControlRegisterAccesses;
    WHV_PROCESSOR_INTERCEPT_COUNTER IoInstructions;
    WHV_PROCESSOR_INTERCEPT_COUNTER HaltInstructions;
    WHV_PROCESSOR_INTERCEPT_COUNTER CpuidInstructions;
    WHV_PROCESSOR_INTERCEPT_COUNTER MsrAccesses;
    WHV_PROCESSOR_INTERCEPT_COUNTER OtherIntercepts;
    WHV_PROCESSOR_INTERCEPT_COUNTER PendingInterrupts;
    WHV_PROCESSOR_INTERCEPT_COUNTER EmulatedInstructions;
    WHV_PROCESSOR_INTERCEPT_COUNTER DebugRegisterAccesses;
    WHV_PROCESSOR_INTERCEPT_COUNTER PageFaultIntercepts;
    WHV_PROCESSOR_INTERCEPT_COUNTER NestedPageFaultIntercepts;
    WHV_PROCESSOR_INTERCEPT_COUNTER Hypercalls;
    WHV_PROCESSOR_INTERCEPT_COUNTER RdpmcInstructions;

#elif defined(_ARM64_)

    WHV_PROCESSOR_INTERCEPT_COUNTER OtherIntercepts;
    WHV_PROCESSOR_INTERCEPT_COUNTER PendingInterrupts;
    WHV_PROCESSOR_INTERCEPT_COUNTER NestedPageFaultIntercepts;
    WHV_PROCESSOR_INTERCEPT_COUNTER Hypercalls;

#endif

} WHV_PROCESSOR_ACTIVITY_COUNTERS;

#if defined(_AMD64_)

C_ASSERT(sizeof(WHV_PROCESSOR_ACTIVITY_COUNTERS) == 224);

#else

C_ASSERT(sizeof(WHV_PROCESSOR_ACTIVITY_COUNTERS) == 64);

#endif

typedef struct WHV_PROCESSOR_EVENT_COUNTERS
{
    UINT64 PageFaultCount;
    UINT64 ExceptionCount;
    UINT64 InterruptCount;
} WHV_PROCESSOR_GUEST_EVENT_COUNTERS;

C_ASSERT(sizeof(WHV_PROCESSOR_GUEST_EVENT_COUNTERS) == 24);

#if defined(_AMD64_)

typedef struct WHV_PROCESSOR_APIC_COUNTERS
{
    UINT64 MmioAccessCount;
    UINT64 EoiAccessCount;
    UINT64 TprAccessCount;
    UINT64 SentIpiCount;
    UINT64 SelfIpiCount;
} WHV_PROCESSOR_APIC_COUNTERS;

C_ASSERT(sizeof(WHV_PROCESSOR_APIC_COUNTERS) == 40);

#endif // defined(_AMD64_)

typedef struct WHV_PROCESSOR_SYNTHETIC_FEATURES_COUNTERS
{
    UINT64 SyntheticInterruptsCount;
    UINT64 LongSpinWaitHypercallsCount;
    UINT64 OtherHypercallsCount;
    UINT64 SyntheticInterruptHypercallsCount;
    UINT64 VirtualInterruptHypercallsCount;
    UINT64 VirtualMmuHypercallsCount;
} WHV_PROCESSOR_SYNTHETIC_FEATURES_COUNTERS;

C_ASSERT(sizeof(WHV_PROCESSOR_SYNTHETIC_FEATURES_COUNTERS) == 48);

// WHvQueryVtlProtectionMaskRange and WHvSetVtlProtectionMaskRange type.
typedef union WHV_VTL_PERMISSION_SET
{
    UINT32 AsUINT32;

    struct
    {
        // VTL permissions for the GPA page, starting from VTL 1.
        UINT16 VtlPermissionFrom1[2];
    };
} WHV_VTL_PERMISSION_SET;

// WHvAdviseGpaRange types
typedef enum WHV_ADVISE_GPA_RANGE_CODE
{
    WHvAdviseGpaRangeCodePopulate         = 0x00000000,
    WHvAdviseGpaRangeCodePin              = 0x00000001,
    WHvAdviseGpaRangeCodeUnpin            = 0x00000002,
} WHV_ADVISE_GPA_RANGE_CODE;

// WHvGetVirtualProcessorState and WHvSetVirtualProcessorState types.
typedef enum WHV_VIRTUAL_PROCESSOR_STATE_TYPE
{
    WHvVirtualProcessorStateTypeSynicMessagePage          = 0x00000000,
    WHvVirtualProcessorStateTypeSynicEventFlagPage        = 0x00000001,

#if defined(_AMD64_)
    WHvVirtualProcessorStateTypeSynicTimerState           = 0x00000002,

    WHvVirtualProcessorStateTypeInterruptControllerState2 = 0x00001000,
    WHvVirtualProcessorStateTypeXsaveState                = 0x00001001,
    WHvVirtualProcessorStateTypeNestedState               = 0x00001002,
#endif
} WHV_VIRTUAL_PROCESSOR_STATE_TYPE;

// Data structures for WHvVirtualProcessorStateTypeNestedState

typedef enum WHV_NESTED_STATE_TYPE
{
    WHvNestedStateTypeVmx,
    WHvNestedStateTypeSvm,

} WHV_NESTED_STATE_TYPE;

typedef struct WHV_NESTED_ENLIGHTENMENTS_CONTROL
{
    union
    {
        UINT32 AsUINT32;

        struct
        {
            UINT32 DirectHypercall:1;
            UINT32 VirtualizationException:1;
            UINT32 Reserved:30;
        };

    } Features;

    union
    {
        UINT32 AsUINT32;

        struct
        {
            UINT32 InterPartitionCommunication:1;
            UINT32 Reserved:31;
        };

    } HypercallControls;

} WHV_NESTED_ENLIGHTENMENTS_CONTROL;

typedef struct WHV_X64_VMX_NESTED_STATE
{
    WHV_NESTED_STATE_TYPE Vendor;

    struct
    {
        //
        // Indicates whether the VP is currently in nested guest mode.
        //
        UINT32 GuestMode : 1;

        //
        // Indicates if VMXON was executed.
        //
        UINT32 Vmxon : 1;

        //
        // Indicates if the VP has a current VMCS.
        //
        UINT32 CurrentVmcsValid : 1;

        //
        // Indicates if a physical VM-Entry is pending.
        //
        UINT32 VmEntryPending : 1;

        //
        // Indicates if the current VMCS is enlightened.
        //
        UINT32 VmcsEnlightened : 1;

        //
        // Indicates if enlightened VM entry is enabled.
        //
        UINT32 EnlightenedVmEntry : 1;

        UINT32 Reserved : 26;
    } Flags;

    //
    // Nested hypervisor enlightement control register.
    //
    WHV_NESTED_ENLIGHTENMENTS_CONTROL NestedEnlightenmentsControl;

    //
    // Loaded PDPTs if guest in PAE mode without EPT.
    //
    UINT64 Pdpt[4];

    //
    // GPA of the VMXON region.
    //
    UINT64 VmxonRegionGpa;

    //
    // GPA of current VMCS.
    //
    UINT64 VmcsGpa;

    //
    // GPA of the current enlightened VMCS.
    //
    UINT64 CurrentEnlightenedVmcs;

    //
    // Virtualized APIC registers.
    //
    struct
    {
        UINT32 Tpr;
        UINT32 Ppr;
        UINT32 Isr[8];
        UINT32 Irr[8];
        UINT32 IcrLow;
        UINT32 IcrHigh;
    } VirtualApicRegs;

    UINT8 Reserved[3944];

    //
    // Current VMCS, see definition of enlightened VMCS in TLFS 16.11.2.
    //
    DECLSPEC_ALIGN(4096) UINT8 VmcsBytes[4096];

} WHV_X64_VMX_NESTED_STATE;

#pragma pack(push,1)

typedef struct WHV_SVM_VMCB_SELECTOR
{
    UINT16  Selector;
    UINT16  Attrib;
    UINT32  Limit;
    UINT64  Base;   // For all but GS/FS only lower 32 bits used

} WHV_SVM_VMCB_SELECTOR;

#pragma pack (pop)

//
// Nested host state used for internal and EXO save chunks.
//

typedef struct WHV_SVM_NESTED_HOST_STATE
{
    UINT64 Rip;
    UINT64 Rsp;
    UINT64 Rflags;
    UINT64 Rax;
    WHV_SVM_VMCB_SELECTOR Es;
    WHV_SVM_VMCB_SELECTOR Cs;
    WHV_SVM_VMCB_SELECTOR Ss;
    WHV_SVM_VMCB_SELECTOR Ds;
    WHV_SVM_VMCB_SELECTOR Gdtr;
    WHV_SVM_VMCB_SELECTOR Idtr;
    UINT64 Efer;
    UINT64 Cr0;
    UINT64 Cr3;
    UINT64 Cr4;
    UINT64 VirtualTpr;

    //
    // Reserved for future host state.
    //
    UINT64 Reserved[6];

} WHV_SVM_NESTED_HOST_STATE;

typedef struct WHV_X64_SVM_NESTED_STATE
{
    WHV_NESTED_STATE_TYPE Vendor;

    struct
    {
        //
        // Indicates if the VP is currently in nested guest mode.
        //
        UINT32 GuestMode : 1;

        //
        // Indicates if a physical VM-Entry is pending.
        //
        UINT32 VmEntryPending : 1;

        //
        // Indicates if the Host Save GPA is valid.
        //
        UINT32 HostSaveGpaValid : 1;

        //
        // Indicates if there is a current VMCB.
        //
        UINT32 CurrentVmcbValid : 1;

        UINT32 Reserved : 28;
    } Flags;

    //
    // Nested hypervisor enlightement control register.
    //
    WHV_NESTED_ENLIGHTENMENTS_CONTROL NestedEnlightenmentsControl;

    //
    // Host Save GPA.
    //
    UINT64 HostSaveGpa;

    //
    // VM_CR MSR.
    //
    UINT64 VmControlMsr;

    //
    // TSC ratio MSR.
    //
    UINT64 VirtualTscRatioMsr;

    //
    // GPA of the current VMCB.
    //
    UINT64 VmcbGpa;

    //
    // Specifies the current host state if the VP is currently in guest mode.
    //
    WHV_SVM_NESTED_HOST_STATE HostState;

    UINT8 Reserved[3832];

    //
    // Specifices the current VMCB if the VP is currently in guest mode. Format is as specified by AMD.
    //
    DECLSPEC_ALIGN(4096) UINT8 VmcbBytes[4096];

} WHV_X64_SVM_NESTED_STATE;

typedef union WHV_X64_NESTED_STATE
{
    WHV_X64_VMX_NESTED_STATE Vmx;
    WHV_X64_SVM_NESTED_STATE Svm;

} WHV_X64_NESTED_STATE;

C_ASSERT(sizeof(WHV_X64_NESTED_STATE) == (2 * 4096));

//
// Synic definitions
//

typedef struct WHV_SYNIC_EVENT_PARAMETERS
{
    UINT32 VpIndex;
    UINT8 TargetSint;
    WHV_VTL TargetVtl;
    UINT16 FlagNumber;
} WHV_SYNIC_EVENT_PARAMETERS;

C_ASSERT(sizeof(WHV_SYNIC_EVENT_PARAMETERS) == 8);

//
// Virtual PCI type definitions.
//

typedef enum WHV_ALLOCATE_VPCI_RESOURCE_FLAGS
{
    WHvAllocateVpciResourceFlagNone = 0x00000000,
    WHvAllocateVpciResourceFlagAllowDirectP2P = 0x00000001

} WHV_ALLOCATE_VPCI_RESOURCE_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_ALLOCATE_VPCI_RESOURCE_FLAGS);

#define WHV_MAX_DEVICE_ID_SIZE_IN_CHARS 200 // PnP manager limit

typedef struct WHV_SRIOV_RESOURCE_DESCRIPTOR
{
    WCHAR PnpInstanceId[WHV_MAX_DEVICE_ID_SIZE_IN_CHARS];
    LUID VirtualFunctionId;
    UINT16 VirtualFunctionIndex;
    UINT16 Reserved;

} WHV_SRIOV_RESOURCE_DESCRIPTOR;

C_ASSERT(sizeof(WHV_SRIOV_RESOURCE_DESCRIPTOR) == 412);

typedef enum WHV_VPCI_DEVICE_NOTIFICATION_TYPE
{
    WHvVpciDeviceNotificationUndefined = 0,
    WHvVpciDeviceNotificationMmioRemapping = 1,
    WHvVpciDeviceNotificationSurpriseRemoval = 2

} WHV_VPCI_DEVICE_NOTIFICATION_TYPE;

typedef struct WHV_VPCI_DEVICE_NOTIFICATION
{
    WHV_VPCI_DEVICE_NOTIFICATION_TYPE NotificationType;
    UINT32 Reserved1;
    union
    {
        UINT64 Reserved2;
    };

} WHV_VPCI_DEVICE_NOTIFICATION;

C_ASSERT(sizeof(WHV_VPCI_DEVICE_NOTIFICATION) == 16);

typedef enum WHV_CREATE_VPCI_DEVICE_FLAGS
{
    WHvCreateVpciDeviceFlagNone = 0x00000000,
    WHvCreateVpciDeviceFlagPhysicallyBacked = 0x00000001,
    WHvCreateVpciDeviceFlagUseLogicalInterrupts = 0x00000002

} WHV_CREATE_VPCI_DEVICE_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_CREATE_VPCI_DEVICE_FLAGS);

typedef enum WHV_VPCI_DEVICE_PROPERTY_CODE
{
    WHvVpciDevicePropertyCodeUndefined   = 0,
    WHvVpciDevicePropertyCodeHardwareIDs = 1,
    WHvVpciDevicePropertyCodeProbedBARs  = 2

} WHV_VPCI_DEVICE_PROPERTY_CODE;

typedef struct WHV_VPCI_HARDWARE_IDS
{
    UINT16 VendorID;
    UINT16 DeviceID;
    UINT8 RevisionID;
    UINT8 ProgIf;
    UINT8 SubClass;
    UINT8 BaseClass;
    UINT16 SubVendorID;
    UINT16 SubSystemID;

} WHV_VPCI_HARDWARE_IDS;

C_ASSERT(sizeof(WHV_VPCI_HARDWARE_IDS) == 12);

#define WHV_VPCI_TYPE0_BAR_COUNT 6

typedef struct WHV_VPCI_PROBED_BARS
{
    UINT32 Value[WHV_VPCI_TYPE0_BAR_COUNT];

} WHV_VPCI_PROBED_BARS;

C_ASSERT(sizeof(WHV_VPCI_PROBED_BARS) == 24);

typedef enum WHV_VPCI_MMIO_RANGE_FLAGS
{
    WHvVpciMmioRangeFlagReadAccess = 0x00000001,
    WHvVpciMmioRangeFlagWriteAccess = 0x00000002

} WHV_VPCI_MMIO_RANGE_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_VPCI_MMIO_RANGE_FLAGS);

typedef enum WHV_VPCI_DEVICE_REGISTER_SPACE
{
    WHvVpciConfigSpace = -1,
    WHvVpciBar0 = 0,
    WHvVpciBar1 = 1,
    WHvVpciBar2 = 2,
    WHvVpciBar3 = 3,
    WHvVpciBar4 = 4,
    WHvVpciBar5 = 5

} WHV_VPCI_DEVICE_REGISTER_SPACE;

typedef struct WHV_VPCI_MMIO_MAPPING
{
    WHV_VPCI_DEVICE_REGISTER_SPACE Location;
    WHV_VPCI_MMIO_RANGE_FLAGS Flags;
    UINT64 SizeInBytes;
    UINT64 OffsetInBytes;
    PVOID VirtualAddress;

} WHV_VPCI_MMIO_MAPPING;

C_ASSERT(sizeof(WHV_VPCI_MMIO_MAPPING) == 32);

typedef struct WHV_VPCI_DEVICE_REGISTER
{
    WHV_VPCI_DEVICE_REGISTER_SPACE Location;
    UINT32 SizeInBytes;
    UINT64 OffsetInBytes;

} WHV_VPCI_DEVICE_REGISTER;

C_ASSERT(sizeof(WHV_VPCI_DEVICE_REGISTER) == 16);

typedef enum WHV_VPCI_INTERRUPT_TARGET_FLAGS
{
    WHvVpciInterruptTargetFlagNone      = 0x00000000,
    WHvVpciInterruptTargetFlagMulticast = 0x00000001,

} WHV_VPCI_INTERRUPT_TARGET_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_VPCI_INTERRUPT_TARGET_FLAGS);

typedef struct WHV_VPCI_INTERRUPT_TARGET
{
    UINT32 Vector;
    WHV_VPCI_INTERRUPT_TARGET_FLAGS Flags;
    UINT32 ProcessorCount;
    UINT32 Processors[ANYSIZE_ARRAY];

} WHV_VPCI_INTERRUPT_TARGET;

C_ASSERT(sizeof(WHV_VPCI_INTERRUPT_TARGET) == 16);

//
// Triggers
//

typedef enum WHV_TRIGGER_TYPE
{
#if defined(_AMD64_)
    WHvTriggerTypeInterrupt = 0,
#endif
    WHvTriggerTypeSynicEvent = 1,
    WHvTriggerTypeDeviceInterrupt = 2,
} WHV_TRIGGER_TYPE;

typedef struct WHV_TRIGGER_PARAMETERS
{
    WHV_TRIGGER_TYPE TriggerType;
    UINT32 Reserved;
    union
    {
#if defined(_AMD64_)
        WHV_INTERRUPT_CONTROL Interrupt;
#endif
        WHV_SYNIC_EVENT_PARAMETERS SynicEvent;
        struct
        {
            UINT64 LogicalDeviceId;
            UINT64 MsiAddress;
            UINT32 MsiData;
            UINT32 Reserved;
        } DeviceInterrupt;
    };
} WHV_TRIGGER_PARAMETERS;

C_ASSERT(sizeof(WHV_TRIGGER_PARAMETERS) == 32);

typedef PVOID WHV_TRIGGER_HANDLE;

typedef enum WHV_VIRTUAL_PROCESSOR_PROPERTY_CODE
{
    WHvVirtualProcessorPropertyCodeNumaNode = 0x00000000,
} WHV_VIRTUAL_PROCESSOR_PROPERTY_CODE;

typedef struct WHV_VIRTUAL_PROCESSOR_PROPERTY
{
    WHV_VIRTUAL_PROCESSOR_PROPERTY_CODE PropertyCode;
    UINT32 Reserved;
    union
    {
        USHORT NumaNode;
        UINT64 Padding;
    };
} WHV_VIRTUAL_PROCESSOR_PROPERTY;

C_ASSERT(sizeof(WHV_VIRTUAL_PROCESSOR_PROPERTY) == 16);

//
// Notification ports
//

typedef enum WHV_NOTIFICATION_PORT_TYPE
{
    WHvNotificationPortTypeEvent = 2,
    WHvNotificationPortTypeDoorbell = 4,
} WHV_NOTIFICATION_PORT_TYPE;

typedef struct WHV_NOTIFICATION_PORT_PARAMETERS
{
    WHV_NOTIFICATION_PORT_TYPE NotificationPortType;
    UINT16 Reserved;
    UINT8 Reserved1;
    UINT8 ConnectionVtl;

    union
    {
        WHV_DOORBELL_MATCH_DATA Doorbell;
        struct
        {
            UINT32 ConnectionId;
        } Event;
    };

} WHV_NOTIFICATION_PORT_PARAMETERS;

C_ASSERT(sizeof(WHV_NOTIFICATION_PORT_PARAMETERS) == 32);

typedef enum WHV_NOTIFICATION_PORT_PROPERTY_CODE
{
    WHvNotificationPortPropertyPreferredTargetVp = 1,
    WHvNotificationPortPropertyPreferredTargetDuration = 5,
} WHV_NOTIFICATION_PORT_PROPERTY_CODE;

typedef UINT64 WHV_NOTIFICATION_PORT_PROPERTY;

//
// The preferred target VP defaults to any VP.
//

#define WHV_ANY_VP (0xFFFFFFFF)

//
// Define the maximum possible value for the preferred target duration.
//

#define WHV_NOTIFICATION_PORT_PREFERRED_DURATION_MAX (0xFFFFFFFFFFFFFFFFUI64)

typedef PVOID WHV_NOTIFICATION_PORT_HANDLE;

//
// Post message
//

#define WHV_SYNIC_MESSAGE_SIZE  256

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif

#endif // defined(_AMD64_) || defined(_ARM64_)

#endif // _WINHVAPIDEFS_H_
