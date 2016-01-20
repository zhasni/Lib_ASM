section .text
	global _ft_bzero

_ft_bzero:
	mov rcx, 0
	cmp rdi, 0
	je .ret

.loop:
	cmp rcx, rsi
	je	.ret
	mov byte [rdi + rcx], 0
	inc rcx
	jmp	.loop

.ret:
	ret