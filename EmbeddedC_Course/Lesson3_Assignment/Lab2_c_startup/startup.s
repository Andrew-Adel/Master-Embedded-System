	.syntax unified
	.cpu cortex-m3
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.thumb
	.file	"startup.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.align	2
	.global	Rest_Handler
	.thumb
	.thumb_func
	.type	Rest_Handler, %function
Rest_Handler:
.LFB0:
	.file 1 "startup.c"
	.loc 1 18 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
.LCFI0:
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	sub	sp, sp, #24
.LCFI1:
	.cfi_def_cfa_offset 32
	add	r7, sp, #0
.LCFI2:
	.cfi_def_cfa_register 7
	.loc 1 19 0
	movw	r2, #:lower16:_E_DATA
	movt	r2, #:upper16:_E_DATA
	movw	r3, #:lower16:_S_DATA
	movt	r3, #:upper16:_S_DATA
	subs	r3, r2, r3
	str	r3, [r7, #8]
	.loc 1 20 0
	movw	r3, #:lower16:_E_TEXT
	movt	r3, #:upper16:_E_TEXT
	str	r3, [r7, #20]
	.loc 1 21 0
	movw	r3, #:lower16:_S_DATA
	movt	r3, #:upper16:_S_DATA
	str	r3, [r7, #16]
	.loc 1 23 0
	mov	r3, #0
	str	r3, [r7, #12]
	b	.L2
.L3:
	.loc 1 25 0 discriminator 2
	ldr	r3, [r7, #20]
	ldrb	r2, [r3, #0]	@ zero_extendqisi2
	ldr	r3, [r7, #16]
	strb	r2, [r3, #0]
	ldr	r3, [r7, #16]
	add	r3, r3, #1
	str	r3, [r7, #16]
	ldr	r3, [r7, #20]
	add	r3, r3, #1
	str	r3, [r7, #20]
	.loc 1 23 0 discriminator 2
	ldr	r3, [r7, #12]
	add	r3, r3, #1
	str	r3, [r7, #12]
.L2:
	.loc 1 23 0 is_stmt 0 discriminator 1
	ldr	r2, [r7, #12]
	ldr	r3, [r7, #8]
	cmp	r2, r3
	bcc	.L3
	.loc 1 28 0 is_stmt 1
	movw	r2, #:lower16:_E_BSS
	movt	r2, #:upper16:_E_BSS
	movw	r3, #:lower16:_S_BSS
	movt	r3, #:upper16:_S_BSS
	subs	r3, r2, r3
	str	r3, [r7, #4]
	.loc 1 29 0
	movw	r3, #:lower16:_S_BSS
	movt	r3, #:upper16:_S_BSS
	str	r3, [r7, #16]
	.loc 1 30 0
	mov	r3, #0
	str	r3, [r7, #12]
	b	.L4
.L5:
	.loc 1 32 0 discriminator 2
	mov	r3, #0
	ldrb	r2, [r3, #0]	@ zero_extendqisi2
	ldr	r3, [r7, #16]
	strb	r2, [r3, #0]
	ldr	r3, [r7, #16]
	add	r3, r3, #1
	str	r3, [r7, #16]
	.loc 1 30 0 discriminator 2
	ldr	r3, [r7, #12]
	add	r3, r3, #1
	str	r3, [r7, #12]
.L4:
	.loc 1 30 0 is_stmt 0 discriminator 1
	ldr	r2, [r7, #12]
	ldr	r3, [r7, #4]
	cmp	r2, r3
	bcc	.L5
	.loc 1 36 0 is_stmt 1
	bl	main
	.loc 1 37 0
	add	r7, r7, #24
	mov	sp, r7
	pop	{r7, pc}
	.cfi_endproc
.LFE0:
	.size	Rest_Handler, .-Rest_Handler
	.align	2
	.global	Default_Handler
	.thumb
	.thumb_func
	.type	Default_Handler, %function
Default_Handler:
.LFB1:
	.loc 1 38 0
	.cfi_startproc
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
.LCFI3:
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	add	r7, sp, #0
.LCFI4:
	.cfi_def_cfa_register 7
	.loc 1 39 0
	bl	Rest_Handler
	.loc 1 40 0
	pop	{r7, pc}
	.cfi_endproc
.LFE1:
	.size	Default_Handler, .-Default_Handler
	.weak	H_Fault_Handler
	.thumb_set H_Fault_Handler,Default_Handler
	.weak	MM_Fault_Handler
	.thumb_set MM_Fault_Handler,Default_Handler
	.weak	Bus_Fault_Handler
	.thumb_set Bus_Fault_Handler,Default_Handler
	.weak	Usage_Fault_Handler
	.thumb_set Usage_Fault_Handler,Default_Handler
	.weak	NMI_Handler
	.thumb_set NMI_Handler,Default_Handler
	.global	vectors
	.section	.vectors,"aw",%progbits
	.align	2
	.type	vectors, %object
	.size	vectors, 28
vectors:
	.word	_stack_top
	.word	Rest_Handler
	.word	NMI_Handler
	.word	H_Fault_Handler
	.word	MM_Fault_Handler
	.word	Bus_Fault_Handler
	.word	Usage_Fault_Handler
	.text
.Letext0:
	.file 2 "platform_types.h"
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0x17e
	.2byte	0x2
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF25
	.byte	0x1
	.4byte	.LASF26
	.4byte	.LASF27
	.4byte	.Ltext0
	.4byte	.Letext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF2
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF3
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF4
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF7
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF8
	.uleb128 0x4
	.4byte	.LASF9
	.byte	0x2
	.byte	0x1c
	.4byte	0x2c
	.uleb128 0x4
	.4byte	.LASF10
	.byte	0x2
	.byte	0x20
	.4byte	0x48
	.uleb128 0x2
	.byte	0x4
	.byte	0x4
	.4byte	.LASF11
	.uleb128 0x2
	.byte	0x8
	.byte	0x4
	.4byte	.LASF12
	.uleb128 0x5
	.byte	0x1
	.4byte	.LASF28
	.byte	0x1
	.byte	0x12
	.byte	0x1
	.4byte	.LFB0
	.4byte	.LFE0
	.4byte	.LLST0
	.byte	0x1
	.4byte	0xee
	.uleb128 0x6
	.4byte	.LASF13
	.byte	0x1
	.byte	0x13
	.4byte	0x76
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x6
	.4byte	.LASF14
	.byte	0x1
	.byte	0x14
	.4byte	0xee
	.byte	0x2
	.byte	0x91
	.sleb128 -12
	.uleb128 0x6
	.4byte	.LASF15
	.byte	0x1
	.byte	0x15
	.4byte	0xee
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x7
	.ascii	"i\000"
	.byte	0x1
	.byte	0x16
	.4byte	0x5d
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x6
	.4byte	.LASF16
	.byte	0x1
	.byte	0x1c
	.4byte	0x76
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.uleb128 0x8
	.byte	0x4
	.4byte	0x6b
	.uleb128 0x9
	.byte	0x1
	.4byte	.LASF29
	.byte	0x1
	.byte	0x26
	.byte	0x1
	.4byte	.LFB1
	.4byte	.LFE1
	.4byte	.LLST1
	.byte	0x1
	.uleb128 0xa
	.4byte	.LASF17
	.byte	0x1
	.byte	0x8
	.4byte	0x76
	.byte	0x1
	.byte	0x1
	.uleb128 0xa
	.4byte	.LASF18
	.byte	0x1
	.byte	0x9
	.4byte	0x76
	.byte	0x1
	.byte	0x1
	.uleb128 0xa
	.4byte	.LASF19
	.byte	0x1
	.byte	0xa
	.4byte	0x76
	.byte	0x1
	.byte	0x1
	.uleb128 0xa
	.4byte	.LASF20
	.byte	0x1
	.byte	0xb
	.4byte	0x76
	.byte	0x1
	.byte	0x1
	.uleb128 0xa
	.4byte	.LASF21
	.byte	0x1
	.byte	0xc
	.4byte	0x76
	.byte	0x1
	.byte	0x1
	.uleb128 0xa
	.4byte	.LASF22
	.byte	0x1
	.byte	0xd
	.4byte	0x76
	.byte	0x1
	.byte	0x1
	.uleb128 0xb
	.4byte	0x76
	.4byte	0x168
	.uleb128 0xc
	.4byte	0x168
	.byte	0x6
	.byte	0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF23
	.uleb128 0xd
	.4byte	.LASF24
	.byte	0x1
	.byte	0x2f
	.4byte	0x158
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.4byte	vectors
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
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
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x2116
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x2116
	.uleb128 0xc
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",%progbits
.Ldebug_loc0:
.LLST0:
	.4byte	.LFB0-.Ltext0
	.4byte	.LCFI0-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 0
	.4byte	.LCFI0-.Ltext0
	.4byte	.LCFI1-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 8
	.4byte	.LCFI1-.Ltext0
	.4byte	.LCFI2-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 32
	.4byte	.LCFI2-.Ltext0
	.4byte	.LFE0-.Ltext0
	.2byte	0x2
	.byte	0x77
	.sleb128 32
	.4byte	0
	.4byte	0
.LLST1:
	.4byte	.LFB1-.Ltext0
	.4byte	.LCFI3-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 0
	.4byte	.LCFI3-.Ltext0
	.4byte	.LCFI4-.Ltext0
	.2byte	0x2
	.byte	0x7d
	.sleb128 8
	.4byte	.LCFI4-.Ltext0
	.4byte	.LFE1-.Ltext0
	.2byte	0x2
	.byte	0x77
	.sleb128 8
	.4byte	0
	.4byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF26:
	.ascii	"startup.c\000"
.LASF14:
	.ascii	"P_src\000"
.LASF28:
	.ascii	"Rest_Handler\000"
.LASF11:
	.ascii	"float\000"
.LASF1:
	.ascii	"unsigned char\000"
.LASF5:
	.ascii	"long unsigned int\000"
.LASF3:
	.ascii	"short unsigned int\000"
.LASF24:
	.ascii	"vectors\000"
.LASF12:
	.ascii	"double\000"
.LASF21:
	.ascii	"_E_BSS\000"
.LASF22:
	.ascii	"_E_TEXT\000"
.LASF10:
	.ascii	"uint32\000"
.LASF8:
	.ascii	"unsigned int\000"
.LASF7:
	.ascii	"long long unsigned int\000"
.LASF19:
	.ascii	"_E_DATA\000"
.LASF17:
	.ascii	"_stack_top\000"
.LASF23:
	.ascii	"sizetype\000"
.LASF16:
	.ascii	"BSS_SIZE\000"
.LASF6:
	.ascii	"long long int\000"
.LASF29:
	.ascii	"Default_Handler\000"
.LASF25:
	.ascii	"GNU C 4.7.2\000"
.LASF18:
	.ascii	"_S_DATA\000"
.LASF2:
	.ascii	"short int\000"
.LASF15:
	.ascii	"P_dst\000"
.LASF9:
	.ascii	"uint8\000"
.LASF4:
	.ascii	"long int\000"
.LASF20:
	.ascii	"_S_BSS\000"
.LASF27:
	.ascii	"E:\\Courses\\Embedded System KS\\Units\\Unit 3\\rep"
	.ascii	"o\\Master-Embedded-System\\EmbeddedC_Course\\Lesson"
	.ascii	"3_Assignment\\Lab2_c_startup\000"
.LASF0:
	.ascii	"signed char\000"
.LASF13:
	.ascii	"DATA_SIZE\000"
	.ident	"GCC: (GNU) 4.7.2"
