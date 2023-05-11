	.file	"main.c"
	.text
.Ltext0:
	.file 0 "/home/heige/source/src" "../kneral/main.c"
	.globl	message
	.data
	.align 4
	.type	message, @object
	.size	message, 23
message:
	.string	"hello,world. i'm an os"
	.text
	.globl	init_kneral
	.type	init_kneral, @function
init_kneral:
.LFB0:
	.file 1 "../kneral/main.c"
	.loc 1 13 19
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 14 14
	subl	$12, %esp
	pushl	$773
	call	inb@PLT
	addl	$16, %esp
	movb	%al, -17(%ebp)
	.loc 1 15 5
	subl	$8, %esp
	pushl	$14
	pushl	$981
	call	outb@PLT
	addl	$16, %esp
	.loc 1 16 5
	subl	$8, %esp
	pushl	$20
	pushl	$982
	call	outb@PLT
	addl	$16, %esp
	.loc 1 17 5
	subl	$8, %esp
	pushl	$15
	pushl	$981
	call	outb@PLT
	addl	$16, %esp
	.loc 1 18 5
	subl	$8, %esp
	pushl	$20
	pushl	$982
	call	outb@PLT
	addl	$16, %esp
	.loc 1 20 11
	movl	$753664, -12(%ebp)
.LBB2:
	.loc 1 21 14
	movl	$0, -16(%ebp)
	.loc 1 21 5
	jmp	.L2
.L3:
	.loc 1 22 17 discriminator 3
	movl	-16(%ebp), %eax
	addl	%eax, %eax
	movl	%eax, %edx
	.loc 1 22 15 discriminator 3
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	.loc 1 22 30 discriminator 3
	leal	message@GOTOFF(%ebx), %ecx
	movl	-16(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	.loc 1 22 21 discriminator 3
	movb	%al, (%edx)
	.loc 1 21 37 discriminator 3
	addl	$1, -16(%ebp)
.L2:
	.loc 1 21 19 discriminator 1
	movl	-16(%ebp), %eax
	cmpl	$22, %eax
	jbe	.L3
.LBE2:
	.loc 1 25 1
	nop
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	init_kneral, .-init_kneral
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB1:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE1:
	.text
.Letext0:
	.file 2 "/home/heige/source/include/main.h"
	.file 3 "/home/heige/source/include/io.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0xe8
	.value	0x5
	.byte	0x1
	.byte	0x4
	.long	.Ldebug_abbrev0
	.uleb128 0x4
	.long	.LASF6
	.byte	0x1d
	.long	.LASF0
	.long	.LASF1
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x5
	.long	0x3d
	.long	0x36
	.uleb128 0x6
	.long	0x36
	.byte	0x16
	.byte	0
	.uleb128 0x1
	.byte	0x4
	.byte	0x7
	.long	.LASF2
	.uleb128 0x1
	.byte	0x1
	.byte	0x6
	.long	.LASF3
	.uleb128 0x7
	.long	.LASF7
	.byte	0x2
	.byte	0x5
	.byte	0x6
	.long	0x26
	.uleb128 0x5
	.byte	0x3
	.long	message
	.uleb128 0x8
	.long	.LASF8
	.byte	0x3
	.byte	0x7
	.byte	0x6
	.long	0x6d
	.uleb128 0x2
	.long	0x6d
	.uleb128 0x2
	.long	0x3d
	.byte	0
	.uleb128 0x1
	.byte	0x2
	.byte	0x5
	.long	.LASF4
	.uleb128 0x9
	.string	"inb"
	.byte	0x3
	.byte	0x4
	.byte	0x6
	.long	0x3d
	.long	0x8a
	.uleb128 0x2
	.long	0x6d
	.byte	0
	.uleb128 0xa
	.long	.LASF9
	.byte	0x1
	.byte	0xd
	.byte	0x6
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.long	0xde
	.uleb128 0x3
	.string	"a"
	.byte	0xe
	.byte	0xa
	.long	0x3d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -25
	.uleb128 0xb
	.long	.LASF10
	.byte	0x1
	.byte	0x13
	.byte	0xa
	.long	0x3d
	.uleb128 0xc
	.long	.LASF5
	.byte	0x1
	.byte	0x14
	.byte	0xb
	.long	0xde
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xd
	.long	.LBB2
	.long	.LBE2-.LBB2
	.uleb128 0x3
	.string	"i"
	.byte	0x15
	.byte	0xe
	.long	0xe4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.byte	0
	.uleb128 0xe
	.byte	0x4
	.long	0x3d
	.uleb128 0xf
	.byte	0x4
	.byte	0x5
	.string	"int"
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
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
	.uleb128 0x2
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x8
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
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
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
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
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
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
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
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.value	0
	.value	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF2:
	.string	"unsigned int"
.LASF7:
	.string	"message"
.LASF8:
	.string	"outb"
.LASF4:
	.string	"short int"
.LASF3:
	.string	"char"
.LASF9:
	.string	"init_kneral"
.LASF10:
	.string	"one_little"
.LASF6:
	.string	"GNU C17 12.2.1 20230201 -m32 -mtune=generic -march=x86-64 -g"
.LASF5:
	.string	"screen"
	.section	.debug_line_str,"MS",@progbits,1
.LASF0:
	.string	"../kneral/main.c"
.LASF1:
	.string	"/home/heige/source/src"
	.ident	"GCC: (GNU) 12.2.1 20230201"
	.section	.note.GNU-stack,"",@progbits
