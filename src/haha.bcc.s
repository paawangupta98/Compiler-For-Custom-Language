	.text
	.file	"haha.bcc"
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
	pushq	%rbx
.Ltmp1:
	.cfi_def_cfa_offset 24
	pushq	%rax
.Ltmp2:
	.cfi_def_cfa_offset 32
.Ltmp3:
	.cfi_offset %rbx, -24
.Ltmp4:
	.cfi_offset %rbp, -16
	movl	$.L__unnamed_1, %edi
	movl	$n, %esi
	xorl	%eax, %eax
	callq	scanf
	movl	$.L__unnamed_1, %edi
	movl	$k, %esi
	xorl	%eax, %eax
	callq	scanf
	movl	n(%rip), %ebx
	movl	$1, i(%rip)
	jmp	.LBB0_1
	.align	16, 0x90
.LBB0_2:                                # %forcont
                                        #   in Loop: Header=BB0_1 Depth=1
	movslq	i(%rip), %rax
	leaq	ar(,%rax,4), %rsi
	movl	$.L__unnamed_1, %edi
	xorl	%eax, %eax
	callq	scanf
	incl	%ebp
	movl	%ebp, i(%rip)
.LBB0_1:                                # %for
                                        # =>This Inner Loop Header: Depth=1
	movl	i(%rip), %ebp
	cmpl	%ebx, %ebp
	jbe	.LBB0_2
# BB#3:                                 # %forcontinue
	movl	$0, count(%rip)
	movl	n(%rip), %eax
	movl	$1, i(%rip)
	xorl	%ecx, %ecx
	jmp	.LBB0_4
	.align	16, 0x90
.LBB0_12:                               # %forcontinue10
                                        #   in Loop: Header=BB0_4 Depth=1
	incl	%edx
	movl	%edx, i(%rip)
.LBB0_4:                                # %for3
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_6 Depth 2
	movl	i(%rip), %edx
	cmpl	%eax, %edx
	ja	.LBB0_11
# BB#5:                                 # %forcont4
                                        #   in Loop: Header=BB0_4 Depth=1
	movl	i(%rip), %edi
	incl	%edi
	movl	%edi, m(%rip)
	movl	n(%rip), %esi
	jmp	.LBB0_6
	.align	16, 0x90
.LBB0_10:                               # %ifcontinue
                                        #   in Loop: Header=BB0_6 Depth=2
	incl	%edi
.LBB0_6:                                # %for8
                                        #   Parent Loop BB0_4 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movl	%edi, j(%rip)
	movl	j(%rip), %edi
	cmpl	%esi, %edi
	ja	.LBB0_12
# BB#7:                                 # %forcont9
                                        #   in Loop: Header=BB0_6 Depth=2
	movslq	i(%rip), %rbp
	movl	ar(,%rbp,4), %ebp
	movslq	j(%rip), %rbx
	addl	ar(,%rbx,4), %ebp
	movl	%ebp, sum(%rip)
	cmpl	k(%rip), %ebp
	sete	%bl
	testb	%cl, %cl
	jne	.LBB0_9
# BB#8:                                 # %forcont9
                                        #   in Loop: Header=BB0_6 Depth=2
	testb	%bl, %bl
	je	.LBB0_10
.LBB0_9:                                # %if
                                        #   in Loop: Header=BB0_6 Depth=2
	incl	count(%rip)
	jmp	.LBB0_10
.LBB0_11:                               # %forcontinue5
	movl	$.L__unnamed_2, %edi
	movl	$.L__unnamed_3, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_2, %edi
	movl	$.L__unnamed_4, %esi
	xorl	%eax, %eax
	callq	printf
	movl	count(%rip), %esi
	movl	$.L__unnamed_1, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.L__unnamed_2, %edi
	movl	$.L__unnamed_4, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$1, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	.L__unnamed_4,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_4:
	.asciz	"\n"
	.size	.L__unnamed_4, 2

	.type	.L__unnamed_5,@object   # @1
.L__unnamed_5:
	.asciz	" "
	.size	.L__unnamed_5, 2

	.type	.L__unnamed_1,@object   # @2
.L__unnamed_1:
	.asciz	"%d"
	.size	.L__unnamed_1, 3

	.type	.L__unnamed_2,@object   # @3
.L__unnamed_2:
	.asciz	"%s"
	.size	.L__unnamed_2, 3

	.type	i,@object               # @i
	.comm	i,4,4
	.type	temp,@object            # @temp
	.comm	temp,4,4
	.type	sum,@object             # @sum
	.comm	sum,4,4
	.type	j,@object               # @j
	.comm	j,4,4
	.type	a,@object               # @a
	.comm	a,4,4
	.type	b,@object               # @b
	.comm	b,4,4
	.type	n,@object               # @n
	.comm	n,4,4
	.type	m,@object               # @m
	.comm	m,4,4
	.type	count,@object           # @count
	.comm	count,4,4
	.type	ar,@object              # @ar
	.comm	ar,400000,4
	.type	k,@object               # @k
	.comm	k,4,4
	.type	.L__unnamed_3,@object   # @4
.L__unnamed_3:
	.asciz	"Count = "
	.size	.L__unnamed_3, 9


	.section	".note.GNU-stack","",@progbits
