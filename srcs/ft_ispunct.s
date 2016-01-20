section .text
	global _ft_ispunct

_ft_ispunct:
	cmp rdi, 0
	jb .null
	cmp rdi, 33
	jb .null
	cmp rdi, 48
	jb .ret
	cmp rdi, 58
	jb .null
	cmp rdi, 65
	jb .ret
	mov rax, 0
	ret

.null:
	mov rax, 0
	ret

.ret:
	mov rax, 1
	ret