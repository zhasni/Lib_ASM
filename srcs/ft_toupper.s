section .text
    global _ft_toupper

_ft_toupper:
    cmp rdi, 97
    jb .ret
    cmp rdi, 122
    ja .ret
	sub rdi, 32
	mov rax, rdi
    ret

.ret:
	mov rax, rdi
    ret