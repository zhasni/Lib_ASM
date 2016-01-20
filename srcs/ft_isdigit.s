section .text
	global _ft_isdigit

_ft_isdigit:
	cmp rdi, 57
	ja .null
	cmp rdi, 48
	jb .null
	mov rax, 1
	ret
.null:
	mov rax, 0
	ret