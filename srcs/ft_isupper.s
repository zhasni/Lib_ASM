section .text
	global _ft_isupper

_ft_isupper:
	cmp rdi, 65
	jb .null
	cmp rdi, 90
	ja .null
	mov rax, 1
	ret
.null:
	mov rax, 0
	ret