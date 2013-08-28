.section .data
data_items:
	.long 3, 67, 34, 222, 45, 75, 54, 34, 44, 33, 22, 11, 66, 0
# .long 声明一个数组 每个数占32位。data_items相当于数组名
.section .text

.globl _start
_start:

movl $0, %edi  #初始化edi， 指向数组的第0个元素 edi保存数组中的当前位置 
movl data_items(, %edi, 4), %eax # 4代表每个元素占4个字节  ：数组中第 edi个元素                          的地址是data_items(, %edi, 4),->data_items + edi * 4 
movl %eax, %ebx

start_loop:
	cmpl $0, %eax
	je loop_exit
	incl %edi
	movl data_items(, %edi, 4), %eax
	cmpl %ebx, %eax
	jle start_loop
	movl %eax, %ebx
	jmp start_loop

loop_exit:

movl $1, %eax
int $0x80
