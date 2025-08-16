	.file	"T100DVD.cpp"
 # GNU C++14 (x86_64-posix-seh-rev0, Built by MinGW-W64 project) version 8.1.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 8.1.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.18-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed:  -I ..\..\..\T100Library\Source\T100Library\include
 # -I ..\..\..\T100Host\Source\T100Host\include -I include\hyperv
 # -I include\base -I include\device -I include\skeletal
 # -I C:\zoo\bin\llvm-mingw-20240518-msvcrt-x86_64\include
 # -iprefix C:/zoo/bin/CodeBlocks/MinGW/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/
 # -D_REENTRANT
 # C:\zgit\skynet\Develop\Origin\T100\T100Hypervisor\Source\T100Hypervisor\src\device\T100DVD.cpp
 # -mtune=core2 -march=nocona -g -Wall -fexec-charset=UTF-8
 # -finput-charset=UTF-8 -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations
 # -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
 # -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
 # -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
 # -fchkp-use-static-bounds -fchkp-use-static-const-bounds
 # -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
 # -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
 # -fexceptions -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm
 # -fgnu-runtime -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
 # -fira-share-save-slots -fira-share-spill-slots -fivopts
 # -fkeep-inline-dllexport -fkeep-static-consts -fleading-underscore
 # -flifetime-dse -flto-odr-type-merging -fmath-errno -fmerge-debug-strings
 # -fpeephole -fpic -fplt -fprefetch-loop-arrays -freg-struct-return
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
 # -fset-stack-executable -fshow-column -fshrink-wrap-separate
 # -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
 # -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
 # -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
 # -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
 # -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
 # -funwind-tables -fverbose-asm -fzero-initialized-in-bss
 # -m128bit-long-double -m64 -m80387 -maccumulate-outgoing-args
 # -malign-double -malign-stringops -mcx16 -mfancy-math-387 -mfentry
 # -mfp-ret-in-387 -mfxsr -mieee-fp -mlong-double-80 -mmmx -mms-bitfields
 # -mno-sse4 -mpush-args -mred-zone -msse -msse2 -msse3 -mstack-arg-probe
 # -mstackrealign -mvzeroupper

	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.align 2
	.globl	_ZN7T100DVDC2Ev
	.def	_ZN7T100DVDC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7T100DVDC2Ev
_ZN7T100DVDC2Ev:
.LFB1:
	.file 1 "C:/zgit/skynet/Develop/Origin/T100/T100Hypervisor/Source/T100Hypervisor/src/device/T100DVD.cpp"
	.loc 1 3 1
	.cfi_startproc
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	.cfi_def_cfa_register 6
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # this, this
.LBB2:
 # C:\zgit\skynet\Develop\Origin\T100\T100Hypervisor\Source\T100Hypervisor\src\device\T100DVD.cpp:3: T100DVD::T100DVD()
	.loc 1 3 18
	leaq	16+_ZTV7T100DVD(%rip), %rdx	 #, _1
	movq	16(%rbp), %rax	 # this, tmp88
	movq	%rdx, (%rax)	 # _1, this_3(D)->_vptr.T100DVD
.LBE2:
 # C:\zgit\skynet\Develop\Origin\T100\T100Hypervisor\Source\T100Hypervisor\src\device\T100DVD.cpp:6: }
	.loc 1 6 1
	nop	
	popq	%rbp	 #
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.seh_endproc
	.globl	_ZN7T100DVDC1Ev
	.def	_ZN7T100DVDC1Ev;	.scl	2;	.type	32;	.endef
	.set	_ZN7T100DVDC1Ev,_ZN7T100DVDC2Ev
	.align 2
	.globl	_ZN7T100DVDD2Ev
	.def	_ZN7T100DVDD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7T100DVDD2Ev
_ZN7T100DVDD2Ev:
.LFB4:
	.loc 1 8 1
	.cfi_startproc
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	.cfi_def_cfa_register 6
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # this, this
.LBB3:
 # C:\zgit\skynet\Develop\Origin\T100\T100Hypervisor\Source\T100Hypervisor\src\device\T100DVD.cpp:8: T100DVD::~T100DVD()
	.loc 1 8 19
	leaq	16+_ZTV7T100DVD(%rip), %rdx	 #, _1
	movq	16(%rbp), %rax	 # this, tmp88
	movq	%rdx, (%rax)	 # _1, this_3(D)->_vptr.T100DVD
.LBE3:
 # C:\zgit\skynet\Develop\Origin\T100\T100Hypervisor\Source\T100Hypervisor\src\device\T100DVD.cpp:11: }
	.loc 1 11 1
	nop	
	popq	%rbp	 #
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4:
	.seh_endproc
	.globl	_ZN7T100DVDD1Ev
	.def	_ZN7T100DVDD1Ev;	.scl	2;	.type	32;	.endef
	.set	_ZN7T100DVDD1Ev,_ZN7T100DVDD2Ev
	.align 2
	.globl	_ZN7T100DVDD0Ev
	.def	_ZN7T100DVDD0Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN7T100DVDD0Ev
_ZN7T100DVDD0Ev:
.LFB6:
	.loc 1 8 1
	.cfi_startproc
	pushq	%rbp	 #
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	 #,
	.seh_setframe	%rbp, 0
	.cfi_def_cfa_register 6
	subq	$32, %rsp	 #,
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)	 # this, this
 # C:\zgit\skynet\Develop\Origin\T100\T100Hypervisor\Source\T100Hypervisor\src\device\T100DVD.cpp:11: }
	.loc 1 11 1
	movq	16(%rbp), %rcx	 # this,
	call	_ZN7T100DVDD1Ev	 #
	movl	$8, %edx	 #,
	movq	16(%rbp), %rcx	 # this,
	call	_ZdlPvy	 #
	nop	
	addq	$32, %rsp	 #,
	popq	%rbp	 #
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE6:
	.seh_endproc
	.globl	_ZTV7T100DVD
	.section	.rdata$_ZTV7T100DVD,"dr"
	.linkonce same_size
	.align 8
_ZTV7T100DVD:
	.quad	0
	.quad	_ZTI7T100DVD
	.quad	_ZN7T100DVDD1Ev
	.quad	_ZN7T100DVDD0Ev
	.globl	_ZTI7T100DVD
	.section	.rdata$_ZTI7T100DVD,"dr"
	.linkonce same_size
	.align 8
_ZTI7T100DVD:
 # <anonymous>:
 # <anonymous>:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
 # <anonymous>:
	.quad	_ZTS7T100DVD
	.globl	_ZTS7T100DVD
	.section	.rdata$_ZTS7T100DVD,"dr"
	.linkonce same_size
	.align 8
_ZTS7T100DVD:
	.ascii "7T100DVD\0"
	.text
.Letext0:
	.file 2 "include/device/T100DVD.h"
	.section	.debug_info,"dr"
.Ldebug_info0:
	.long	0x2f8
	.word	0x4
	.secrel32	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.ascii "GNU C++14 8.1.0 -mtune=core2 -march=nocona -g -fexec-charset=UTF-8 -finput-charset=UTF-8\0"
	.byte	0x4
	.ascii "C:\\zgit\\skynet\\Develop\\Origin\\T100\\T100Hypervisor\\Source\\T100Hypervisor\\src\\device\\T100DVD.cpp\0"
	.ascii "C:\\zgit\\skynet\\Develop\\Origin\\T100\\T100Hypervisor\\Source\\T100Hypervisor\0"
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.secrel32	.Ldebug_line0
	.uleb128 0x2
	.secrel32	.LASF0
	.byte	0x8
	.byte	0x2
	.byte	0x5
	.byte	0x7
	.long	0x121
	.long	0x1cd
	.uleb128 0x3
	.secrel32	.LASF0
	.ascii "_ZN7T100DVDC4ERKS_\0"
	.byte	0x1
	.long	0x153
	.long	0x15e
	.uleb128 0x4
	.long	0x1d2
	.uleb128 0x5
	.long	0x1dd
	.byte	0
	.uleb128 0x6
	.ascii "_vptr.T100DVD\0"
	.long	0x1fa
	.byte	0
	.byte	0x1
	.uleb128 0x7
	.secrel32	.LASF0
	.byte	0x1
	.byte	0x3
	.byte	0x1
	.ascii "_ZN7T100DVDC4Ev\0"
	.byte	0x1
	.long	0x194
	.long	0x19a
	.uleb128 0x4
	.long	0x1d2
	.byte	0
	.uleb128 0x8
	.ascii "~T100DVD\0"
	.byte	0x1
	.byte	0x8
	.byte	0x1
	.ascii "_ZN7T100DVDD4Ev\0"
	.byte	0x1
	.long	0x121
	.byte	0x1
	.long	0x1c1
	.uleb128 0x4
	.long	0x1d2
	.uleb128 0x4
	.long	0x1ee
	.byte	0
	.byte	0
	.uleb128 0x9
	.long	0x121
	.uleb128 0xa
	.byte	0x8
	.long	0x121
	.uleb128 0x9
	.long	0x1d2
	.uleb128 0xb
	.byte	0x8
	.long	0x1cd
	.uleb128 0xc
	.long	0x1ee
	.long	0x1ee
	.uleb128 0xd
	.byte	0
	.uleb128 0xe
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x9
	.long	0x1ee
	.uleb128 0xa
	.byte	0x8
	.long	0x200
	.uleb128 0xf
	.byte	0x8
	.ascii "__vtbl_ptr_type\0"
	.long	0x1e3
	.uleb128 0x10
	.long	0x19a
	.long	0x224
	.byte	0
	.long	0x23e
	.uleb128 0x11
	.ascii "this\0"
	.long	0x1d8
	.uleb128 0x11
	.ascii "__in_chrg\0"
	.long	0x1f5
	.byte	0
	.uleb128 0x12
	.long	0x216
	.ascii "_ZN7T100DVDD0Ev\0"
	.long	0x26d
	.quad	.LFB6
	.quad	.LFE6-.LFB6
	.uleb128 0x1
	.byte	0x9c
	.long	0x276
	.uleb128 0x13
	.long	0x224
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x14
	.long	0x216
	.ascii "_ZN7T100DVDD2Ev\0"
	.long	0x2a5
	.quad	.LFB4
	.quad	.LFE4-.LFB4
	.uleb128 0x1
	.byte	0x9c
	.long	0x2ae
	.uleb128 0x13
	.long	0x224
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x10
	.long	0x173
	.long	0x2bc
	.byte	0
	.long	0x2c7
	.uleb128 0x11
	.ascii "this\0"
	.long	0x1d8
	.byte	0
	.uleb128 0x15
	.long	0x2ae
	.ascii "_ZN7T100DVDC2Ev\0"
	.long	0x2f2
	.quad	.LFB1
	.quad	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x13
	.long	0x2bc
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.byte	0
	.section	.debug_abbrev,"dr"
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1b
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x2
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1d
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x34
	.uleb128 0x19
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.uleb128 0x34
	.uleb128 0x19
	.uleb128 0x32
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x4c
	.uleb128 0xb
	.uleb128 0x1d
	.uleb128 0x13
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x64
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x10
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x47
	.uleb128 0x13
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x6e
	.uleb128 0x8
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"dr"
	.long	0x2c
	.word	0x2
	.secrel32	.Ldebug_info0
	.byte	0x8
	.byte	0
	.word	0
	.word	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"dr"
.Ldebug_line0:
	.section	.debug_str,"dr"
.LASF0:
	.ascii "T100DVD\0"
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
