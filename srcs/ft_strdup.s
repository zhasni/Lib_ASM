section .text
	global	_ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:
    cmp rdi, 0
    jle .err
    mov r14, rdi
    call _ft_strlen
    mov r15, rax
    inc rax
    mov rdi, rax
    call _malloc
    cmp rax, 0
    jle .err
    mov rcx, r15
    mov rdi, rax
    mov rsi, r14
    cld
    rep movsb
    ret

.err:
	mov rax, 0
	ret
