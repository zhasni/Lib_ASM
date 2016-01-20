section .text
	global	_ft_strlen
	
_ft_strlen:
	cmp rdi, 0
	je .err
	xor	rcx, rcx
	not	rcx
	xor	rax, rax
	cld
	repne scasb
	not	rcx
	lea	rax, [rcx-1]
	ret

.err:
	mov rax, 0
	ret