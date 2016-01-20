section .text
	global _ft_iscntrl

_ft_iscntrl:
	cmp rdi, 127
	je .ret
	cmp rdi, 0
	jb .null
	cmp rdi, 31
	ja .null
	mov rax, 1
	ret

.null:
	mov rax, 0
	ret

.ret:
	mov rax, 1
	ret