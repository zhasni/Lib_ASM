section .text
    global _ft_isalnum

_ft_isalnum:
    cmp rdi, 122
    ja .null
    cmp rdi, 58
    je .null
    cmp rdi, 59
    je .null
    cmp rdi, 60
    je .null
    cmp rdi, 61
    je .null
    cmp rdi, 62
    je .null
    cmp rdi, 63
    je .null
    cmp rdi, 64
    je .null
    cmp rdi, 48
    jb .null
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