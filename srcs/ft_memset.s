section .text
	global	_ft_memset
	
_ft_memset:

    cmp rdi, 0
    jle .err
    mov rcx, rdx
    mov rax, rsi
    mov r8, rdi
    cld
    rep stosb
    mov rax, r8
    ret

.err:
    mov rax, 0
    ret
