section .text
    global _ft_tolower

_ft_tolower:
    cmp rdi, 65
    jb .ret
    cmp rdi, 90
    ja .ret
    add rdi, 32
    mov rax, rdi
    ret

.ret:
    mov rax, rdi
    ret