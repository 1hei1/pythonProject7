[bits 32]
section .text
extern task_tables
global task_change
task_change :
    ;xchg bx,bx
    
    mov al,0xc
    mov dx,0x70
    out dx,al
    mov dx,0x71
    in al,dx
    call task_tables
    jmp $+2
    jmp $+2
    jmp $+2
    
    ret 