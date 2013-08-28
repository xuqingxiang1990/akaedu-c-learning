	.file	"helloword.c"
	.section	.rodata
.LC0:
	.string	"hello, word\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	movl	$12, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	call	write
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
