	.file	"line.c"
	.section	.rodata
.LC0:
	.string	"<%s>@(%s) line: %d i = %d\n"
.LC1:
	.string	"line.c"
	.text
.globl print
	.type	print, @function
print:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	$100, -12(%ebp)
	movl	$.LC0, %eax
	movl	-12(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	$6, 12(%esp)
	movl	$.LC1, 8(%esp)
	movl	$__func__.1703, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	ret
	.size	print, .-print
	.section	.rodata
.LC2:
	.string	" line = %d\n"
.LC3:
	.string	" file = %s\n"
.LC4:
	.string	" date = %s\n"
.LC5:
	.string	"Aug 11 2013"
.LC6:
	.string	" time = %s\n"
.LC7:
	.string	"11:01:41"
.LC8:
	.string	" func = %s\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$48, %esp
	movl	$.LC0, %eax
	movl	44(%esp), %edx
	movl	%edx, 16(%esp)
	movl	$12, 12(%esp)
	movl	$.LC1, 8(%esp)
	movl	$__func__.1709, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC2, %eax
	movl	$14, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC3, %eax
	movl	$.LC1, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC4, %eax
	movl	$.LC5, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC6, %eax
	movl	$.LC7, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC8, %eax
	movl	$__func__.1709, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.section	.rodata
	.type	__func__.1709, @object
	.size	__func__.1709, 5
__func__.1709:
	.string	"main"
	.type	__func__.1703, @object
	.size	__func__.1703, 6
__func__.1703:
	.string	"print"
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
