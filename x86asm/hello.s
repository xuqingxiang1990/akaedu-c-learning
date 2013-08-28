.section .data
.section .text

.globl _start

_start:
movb $1, %eax
movb $6, %ebx
int $0x80
