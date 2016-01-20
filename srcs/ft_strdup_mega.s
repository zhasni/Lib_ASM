section .text
    global  _ft_strdup
    extern _ft_strlen
    extern _malloc

_ft_strdup:
    cmp rdi, 0
    jle err
    push rdi
    call _ft_strlen
    mov rcx, rax
    push rcx
    mov rdi, rax
    inc rdi
    call _malloc
    cmp rax, 0
    jle err
    pop rcx
    pop rsi
    mov rdi, rax
    cld
    rep movsb
    ret

err:
    mov rax, 0

end:

;@ src dans RSI
;@ est dans RDI

;nb ‘octet a copier dans rcx

;cld // clear direction flag

;rep movsb // tant que RCX != 0, copie rdi[i] = rsi[i]