section .text
	global _ft_isalpha

_ft_isalpha:
	cmp rdi, 65
	jb .null
	cmp rdi, 122
	ja .null
	cmp rdi, 91
	je .null
	cmp rdi, 92
	je .null
	cmp rdi, 93
	je .null
	cmp rdi, 94
	je .null
	cmp rdi, 95
	je .null
	cmp rdi, 96
	je .null
	mov rax, 1
	ret
.null:
	mov rax, 0
	ret
