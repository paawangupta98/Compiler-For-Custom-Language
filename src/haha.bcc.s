	.text
	.file	"haha.bcc"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rax
.Ltmp0:
	.cfi_def_cfa_offset 16
	movl	$6, x0(%rip)
	movl	$-611, yar(%rip)        # imm = 0xFFFFFFFFFFFFFD9D
	movl	$5, x0(%rip)
	movl	$.L__unnamed_1, %edi
	movl	$.L__unnamed_2, %esi
	movl	$.L__unnamed_3, %edx
	movl	$.L__unnamed_4, %ecx
	xorl	%eax, %eax
	callq	printf
	movl	$1, %eax
	popq	%rcx
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	x0,@object              # @x0
	.comm	x0,4,4
	.type	yar,@object             # @yar
	.comm	yar,4,4
	.type	zarray,@object          # @zarray
	.comm	zarray,408,4
	.type	tarrya,@object          # @tarrya
	.comm	tarrya,4,4
	.type	i,@object               # @i
	.comm	i,4,4
	.type	.L__unnamed_5,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_5:
	.asciz	"\n"
	.size	.L__unnamed_5, 2

	.type	.L__unnamed_2,@object   # @1
.L__unnamed_2:
	.asciz	" "
	.size	.L__unnamed_2, 2

	.type	.L__unnamed_1,@object   # @2
.L__unnamed_1:
	.asciz	"haha"
	.size	.L__unnamed_1, 5

	.type	.L__unnamed_6,@object   # @3
.L__unnamed_6:
	.asciz	"\n"
	.size	.L__unnamed_6, 2

	.type	.L__unnamed_4,@object   # @4
.L__unnamed_4:
	.asciz	" "
	.size	.L__unnamed_4, 2

	.type	.L__unnamed_3,@object   # @5
.L__unnamed_3:
	.asciz	"asfd"
	.size	.L__unnamed_3, 5


	.section	".note.GNU-stack","",@progbits
