.section .date   #. 伪操作section 把代码划分成若干段
.section .text
.globl _start
_start:

movl $1, %eax

movl $4, %ebx

int $0x80
