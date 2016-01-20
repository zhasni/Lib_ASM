section .text
	global _ft_isgraph

_ft_isgraph:
	cmp rdi, 33
	jb .null
	cmp rdi, 126
	ja .null
	mov rax, 1
	ret
.null:
	mov rax, 0
	ret