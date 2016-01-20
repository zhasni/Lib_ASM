%define WRITE				0x2000004

section .data
	backn db 0x0a
	nullstr db "(null)", 0x0a

section .text
	global	_ft_putendl
	global	_ft_strlen_loop3

_ft_strlen_loop3:
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

_ft_putendl:
	mov rax, 0
	cmp rdi, 0
	je .null
	call _ft_strlen_loop3 
	mov rsi, rdi
	mov rdi, 1
	mov rdx, rax
	mov rax, WRITE
	syscall
	jc .ret
	mov rdi, 1
	lea rsi, [rel backn]
	mov rdx, 1
	mov rax, WRITE
	syscall
	jc .ret
	mov rax, 10
	ret

.null:
	mov rax, WRITE
    mov rdx, 7
    lea rsi, [rel nullstr]
    syscall
    jc .ret
    mov rax, 10
    ret

.ret:
	mov rax, -1
	ret

