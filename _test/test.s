	.file	"foo.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC6:
	.string	"first byte = %d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB6456:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	andq	$-64, %rsp
	addq	$-128, %rsp
	movdqa	.LC0(%rip), %xmm3
	movdqa	.LC1(%rip), %xmm9
	movq	%fs:40, %rax
	movq	%rax, 120(%rsp)
	movq	%rsp, %rax
	movdqa	.LC3(%rip), %xmm7
	movdqa	.LC2(%rip), %xmm8
	leaq	80(%rsp), %rdx
	movdqa	.LC4(%rip), %xmm6
	movdqa	.LC5(%rip), %xmm5
.L2:
	movdqa	%xmm3, %xmm2
	addq	$16, %rax
	paddd	%xmm9, %xmm3
	movdqa	%xmm2, %xmm4
	movdqa	%xmm2, %xmm1
	movdqa	%xmm2, %xmm0
	paddd	%xmm8, %xmm4
	punpcklwd	%xmm4, %xmm1
	punpckhwd	%xmm4, %xmm0
	movdqa	%xmm1, %xmm4
	punpcklwd	%xmm0, %xmm1
	punpckhwd	%xmm0, %xmm4
	movdqa	%xmm2, %xmm0
	paddd	%xmm6, %xmm2
	paddd	%xmm7, %xmm0
	punpcklwd	%xmm4, %xmm1
	movdqa	%xmm0, %xmm4
	punpcklwd	%xmm2, %xmm0
	pand	%xmm5, %xmm1
	punpckhwd	%xmm2, %xmm4
	movdqa	%xmm0, %xmm2
	punpckhwd	%xmm4, %xmm2
	punpcklwd	%xmm4, %xmm0
	punpcklwd	%xmm2, %xmm0
	pand	%xmm5, %xmm0
	packuswb	%xmm0, %xmm1
	movaps	%xmm1, -16(%rax)
	cmpq	%rax, %rdx
	jne	.L2
	movsbl	60(%rsp), %edx
	xorl	%eax, %eax
	movl	$2, %edi
	leaq	.LC6(%rip), %rsi
	call	__printf_chk@PLT
	movq	120(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L7
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	xorl	%eax, %eax
	ret
.L7:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE6456:
	.size	main, .-main
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
.LC1:
	.long	16
	.long	16
	.long	16
	.long	16
	.align 16
.LC2:
	.long	4
	.long	4
	.long	4
	.long	4
	.align 16
.LC3:
	.long	8
	.long	8
	.long	8
	.long	8
	.align 16
.LC4:
	.long	12
	.long	12
	.long	12
	.long	12
	.align 16
.LC5:
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.value	255
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
