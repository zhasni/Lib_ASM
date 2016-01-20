section .text
	global _ft_isspace

_ft_isspace:
	cmp rdi, 32
	je .ok
	cmp rdi, 9
	jb .ret
	cmp rdi, 13
	ja .ret
	mov rax, 1
	ret
.ret:
	mov rax, 0
	ret
.ok:
	mov rax, 1
	ret