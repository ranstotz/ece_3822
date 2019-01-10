	.file	"f_00.cc"
	.section	.rodata
.LC0:
	.string	"hello world\n"
.LC1:
	.string	"%f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-48(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	atof
	cvtsd2ss	%xmm0, %xmm2
	movss	%xmm2, -20(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	atof
	cvtsd2ss	%xmm0, %xmm3
	movss	%xmm3, -24(%rbp)
	movss	-24(%rbp), %xmm0
	movl	-20(%rbp), %eax
	movaps	%xmm0, %xmm1
	movl	%eax, -40(%rbp)
	movss	-40(%rbp), %xmm0
	call	_Z7add_sinff
	movd	%xmm0, %eax
	movl	%eax, -28(%rbp)
	movss	-24(%rbp), %xmm0
	movl	-20(%rbp), %eax
	movaps	%xmm0, %xmm1
	movl	%eax, -40(%rbp)
	movss	-40(%rbp), %xmm0
	call	_Z8add_sqrtff
	movd	%xmm0, %eax
	movl	%eax, -32(%rbp)
	movq	stdout(%rip), %rax
	movq	%rax, %rcx
	movl	$12, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
	call	fwrite
	cvtss2sd	-28(%rbp), %xmm0
	movq	stdout(%rip), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	movl	$1, %eax
	call	fprintf
	cvtss2sd	-32(%rbp), %xmm0
	movq	stdout(%rip), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	movl	$1, %eax
	call	fprintf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 5.4.0"
	.section	.note.GNU-stack,"",@progbits
