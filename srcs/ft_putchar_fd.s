%define WRITE				0x2000004

section .text
	global _ft_putchar_fd

_ft_putchar_fd:
	cmp rsi, 0
	jle .ret
	mov [rel char], rdi
	mov rdi, rsi
	lea rsi, [rel char]
	mov rdx, 1
	mov rax, WRITE
	syscall
	ret

.ret:
	ret

section .data
    char:    db      ""