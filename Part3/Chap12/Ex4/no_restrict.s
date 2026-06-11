	.file	"restrict_test.c"
	.text
	.p2align 4
	.globl	add_array
	.type	add_array, @function
add_array:
.LFB23:
	.cfi_startproc
	endbr64
	testq	%rdx, %rdx
	je	.L1
	movl	(%rdi), %eax
	leaq	(%rsi,%rdx,4), %rdx
	.p2align 4,,10
	.p2align 3
.L3:
	addl	(%rsi), %eax
	addq	$4, %rsi
	movl	%eax, (%rdi)
	cmpq	%rsi, %rdx
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE23:
	.size	add_array, .-add_array
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Ket qua: %d\n\n"
.LC1:
	.string	"Test Aliasing..."
.LC2:
	.string	"Data[0] sau khi aliasing: %d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$15, %edx
	movl	$1, %edi
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rsi
	call	__printf_chk@PLT
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	movl	$10, %edx
	leaq	.LC2(%rip), %rsi
	xorl	%eax, %eax
	movl	$1, %edi
	call	__printf_chk@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0"
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
