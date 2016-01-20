%define WRITE				0x2000004

section .data
	nullstr db "(null)"

section .text
	global	_ft_putstr_fd
	global	_ft_strlen_fd

_ft_strlen_fd:
	mov rcx, 0
	cmp rdi, 0
	je .ret

.loop:
	cmp byte [rdi + rcx], 0
	je	.ret
	inc rcx
	jmp	.loop

.ret:
	mov rax, rcx
	ret

_ft_putstr_fd:
	mov rax, 0
	cmp rdi, 0
	je .null
	cmp rsi, 0
	jle .ret
	mov r15, rsi
	call _ft_strlen_fd
	mov rsi, rdi
	mov rdi, r15
	mov rdx, rax
	mov rax, WRITE
	syscall
	jc .ret
	ret

.null:
	mov rax, WRITE
    mov rdx, 6
    lea rsi, [rel nullstr]
    syscall
    jc .ret
    ret

.ret:
	ret

