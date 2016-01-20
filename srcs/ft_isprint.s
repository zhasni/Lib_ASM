section .text
	global _ft_isprint

_ft_isprint:
	cmp rdi, 32
	jb .null
	cmp rdi, 126
	ja .null
	mov rax, 1
	ret
.null:
	mov rax, 0
	ret