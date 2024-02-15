org     0x7c00

main:
        mov     ax,         cs
        mov     ss,         ax
        mov     ds,         ax
        mov     es,         ax 

        mov     ax,         msg_start
        call    print 

        call    load
        jc      error

        mov     ax,         msg_success
        call    print

        call    search


        mov     ax,         msg_end
        call    print
        jmp     stop 

error:
        mov     ax,         msg_error
        call    print
        jmp     stop

load:
        mov     bx,         0x8200
        mov     ah,         0x02
        mov     al,         0x01
        mov     cx,         0x01
        mov     dx,         0x00
        int     0x13
        ret

search:
        mov     ax,         0x8200
        mov     bx,         init_file
        call    search_item
        jc      error 




        ret


search_item:

        ret

string_equal:
        mov     si,         ax 
        mov     di,         bx

        cmpsb   
        jnz     string_equal_end


string_equal_end:      
        ret

print:
        mov     si,         ax
print_next:
        mov     al,         [si]
        add     si,         1
        cmp     al,         0x00
        je      print_end

        mov     ah,         0x0e
        mov     bx,         0x0f
        int     0x10
        jmp     print_next

print_end:
        ret 

stop:
        nop 
        jmp     stop

init_file:
        db      "init.bin", 0x00
msg_start:
        db      "hello world!", 0x00
msg_success:
        db      "success", 0x00
msg_error:
        db      "error", 0x00
msg_end:
        db      "stop", 0x00
        times   510-($-$$) db 0x00

        db      0x55, 0xaa

