section .text
	global _ft_isblank

_ft_isblank:
	cmp rdi, 9
	je .ret
	cmp rdi, 32
	je .ret
	mov rax, 0
	ret
.ret:
	mov rax, 1
	ret