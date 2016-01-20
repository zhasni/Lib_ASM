section .text
	global _ft_isxdigit
	extern _ft_isdigit

_ft_isxdigit:
	call _ft_isdigit
	cmp rax, 1
	je .ret
	cmp rdi, 0
	jb .null
	cmp rdi, 65
	jb .null
	cmp rdi, 71
	jb .ret
	cmp rdi, 97
	jb .null
	cmp rdi, 103
	jb .ret
	mov rax, 0
	ret
.null:
	mov rax, 0
	ret
.ret:
	mov rax, 1
	ret