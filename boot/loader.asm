[org 0x1000]

db 0x55,0xaa
mov si, str
;打印
call print

;检查内存大小,并将内存大小存储在save_struct位置
call check_momery

;
call show

;内存检查成功
call success

;初始化全局描述符表
jmp  load_gdt



jmp $

check_momery:
    mov ax,0
    mov es,ax
    mov di,save_struct;设置结构体所写的位置
    mov ebx,0


    
    .loop_check :
    mov eax,0xe820;设置标志参数

    mov ecx,20;设置内存范围结构体的数据宽度为20位字节

    mov edx, 0x534d4150;设置标志位

    int 0x15;启动中断

    jc error;错误
    add di,20

    cmp ebx,0
    jnz  .loop_check

    ret 
show :
    ;mov eax, [save_struct]
    ;mov ebx, [save_struct+8]
    xchg bx,bx
    mov si,save_struct
    call print
    ret 


success :
    mov si,success_msg
    call print
    ret 


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


load_gdt:
    base equ 0
    code_base equ (1<<3)
    data_base equ (2<<3)

    cli
    in al,0x92 ;启用a20总线
    or al,0b10
    out 0x92,al



    lgdt [gdt_place] ;设置gdt
    
    mov eax,cr0
    or eax,1
    mov cr0,eax    ;进入保护模式

    jmp dword code_base:load_ok




gdt_place:    ;存放gdt表地址和大小
dw (gdt_end - gdt_base) - 1
dd gdt_base
gdt_base:
    dd 0,0
    .gdt_code:
    dw 0xffff
    dw base
    db base>>16
    db 0b1_00_1_1010
    db 0b1_1_0_1_1111
    db base>>24
    .gdt_data:
    dw 0xffff
    dw base
    db base>>16
    db 0b1_00_1_0010
    db 0b1_1_0_0_1111
    db base>>24
gdt_end:



;进入32位保护模式   
[bits 32]
load_ok :
    mov ax,data_base  ;设置ds,es,ss,f,gs为数据段
    mov es,ax
    mov ds,ax
    mov fs,ax
    mov ss,ax
    mov esp,0x10000

    
    mov byte [0xb8000],'p'
    mov edi, 0x10000
    mov cx, 200 ;扇区数量
    mov ebx, 10 ;扇区起始地址
    call read_disk
    jmp code_base:0x10000
    jmp $   
    



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
        mov cx, 256
        xchg ebx,ebx
        call .read
        pop cx
        loop .reads

    ret 


    .check :
    mov dx,0x1f7
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
    




    



error:
    mov si ,error_msg
    call print
    ret

ret




str :
    db "loading os" ,10,13,0

error_msg :
    db "check memory error",0

success_msg:
    db "check successful",0

gdt_ok:
    db "gdt load over",0


save_struct:
