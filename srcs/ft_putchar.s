%define WRITE				0x2000004

section .text
	global _ft_putchar

_ft_putchar:
	mov [rel char], rdi
	lea rsi, [rel char]
	mov rdi, 1
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	ret

section .data
    char:    db      ""