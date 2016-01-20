section .text
	global _ft_islower

_ft_islower:
	cmp rdi, 97
	jb .null
	cmp rdi, 122
	ja .null
	mov rax, 1
	ret
.null:
	mov rax, 0
	ret