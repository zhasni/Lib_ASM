section .text
	global	_ft_strcat
	extern	_ft_strlen_loop

_ft_strcat:
	mov rax, 0
	mov r8 , 0
	cmp rdi, 0
	je .ret
	call _ft_strlen_loop
	mov rcx, 0
	jmp .loop_dest
	mov byte [rdi + rcx], 0
	ret

.loop_dest:
	cmp byte [rsi + rcx], 0
	je .ret
	mov r8, rax
	add r8, rcx
	mov r9, [rsi + rcx]
	mov [rdi + r8], r9
	inc rcx
	jmp .loop_dest

.ret:
	inc rcx
    mov rax, rdi
	ret

; section .data
; 	backn db 0x0a
; 	nullstr db "(null)", 0x0a