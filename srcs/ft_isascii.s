section .text
	global _ft_isascii

_ft_isascii:
	cmp rdi, 127
	ja .null
	cmp rdi, 0
	jb .null
	mov rax, 1
	ret
.null:
	mov rax, 0
	ret

