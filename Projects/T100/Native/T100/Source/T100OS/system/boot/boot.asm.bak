org     0x7c00


main:
    mov     ax,     cs
    mov     ss,     ax
    mov     ds,     ax
    mov     es,     ax 

    mov     ax,     msg
    call    print 

    mov     bx,     0x8200
    mov     ah,     0x02
    mov     al,     0x01
    mov     cx,     0x01
    mov     dx,     0x00
    call    load
    jc      stop

    mov     ax,     msg_end
    call    print 

    jmp     stop 




print:
    mov     si,     ax
print_next:
    mov     al,     [si]
    add     si,     1
    cmp     al,     0x00
    je      print_end

    mov     ah,     0x0e
    mov     bx,     0x0f
    int     0x10
    jmp     print_next

print_end:
    ret 


load:
    int     0x13
    ret


stop:
    nop
    jmp     stop


msg:
    db  "hello world!", 0x0a, 0x00
msg_end:
    db  "stop", 0x0a
    times   510-($-$$)  db 0x00

    db  0x55, 0xaa