[org 0x7c00]
;设置显示模式为文本，清空屏幕
mov ax, 3
int 0x10
;初始化寄存器
mov ax,0
mov ds,ax
mov ss,ax
mov es,ax
;显示
mov sp,0x7c00
mov si, src
call print

mov edi, 0x1000
mov cx, 1 ;扇区数量
mov ebx, 2 ;扇区起始地址

call read_disk
mov ax, [0x1000]
cmp ax, 0xaa55
jz 0x1000

jmp $

print :
    mov ah, 0x0e
.next :
    mov al, [si]
    cmp al, 0
    jz .done
    int 0x10
    inc si
    jmp .next
.done :
    ret


read_disk:
    

    mov dx, 0x1f2
    mov al, cl 
    out dx, al

    inc dx;0x1f3
    mov al, bl
    out dx, al

    inc dx;0x1f4
    shr ebx, 8
    mov al, bl
    out dx, al

    inc dx;0x1f5
    shr ebx, 8
    mov al, bl
    out dx, al

    inc dx;0x1f6
    shr ebx, 8
    mov al, bl
    or al, 0b1110_0000
    out dx, al

    inc dx;0x1f7
    mov al, 0x20
    out dx, al

    .reads:

    push cx
    call .check

    mov dx, 0x1f0
    xor ecx, ecx
    mov cx, 256

    call .read
    pop cx
    loop .reads

ret 


    .check :
        in al, dx
        jmp $+2
        jmp $+2
        jmp $+2
        and al, 0b1000_1000
        cmp al, 0b0000_1000
        jnz .check

    ret 
    .read :
        
        in ax, dx
        jmp $+2
        jmp $+2
        jmp $+2
        mov bx, ax
        mov [edi], ax
        add edi, 2
        loop .read
ret
        



src :
    db "hello,world",10,13,0
times 510-($-$$) db 0
db 0x55, 0xaa