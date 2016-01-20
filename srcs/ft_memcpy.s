section .text
	global	_ft_memcpy
	
_ft_memcpy:

    cmp rdi, 0
    jle .err
    mov rcx, rdx
    mov r8, rdi
    cld
    rep movsb
    mov rax, r8
    ret

.err:
    mov rax, 0
    ret
