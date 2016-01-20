%define READ				0x2000003
%define WRITE				0x2000004

section .data
	buffer: db "", 0x0a

section .text
	global	_ft_cat
	extern	_ft_strlen

_ft_cat:
	cmp rdi, 0
	jb .err
	cmp rdi, 255
	ja .err
	mov r8, rdi
.read:
	mov rdi, r8
	lea rsi, [rel buffer]
	mov rdx, 1
	mov rax, READ
	syscall
	cmp rax, 0
	jle .ret
	lea rsi, [rel buffer]
	mov rdx, 1
	mov rdi, 1
	mov rax, WRITE
	syscall
	jmp .read
.ret:
.err:
	ret

