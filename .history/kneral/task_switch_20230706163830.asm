[bits 32]
section .text
extern schedule
global task_change
task_change :
    cli;
    mov al,0xc
    mov dx,0x70
    out dx,al
    mov dx,0x71
    in al,dx
    sti;
    xchg bx,bx
    call schedule
    ;sub eax,68
    mov esp,eax
    popa;
    pop gs
    pop fs
    pop es
    pop ds
    add esp,8

    ;这里将段寄存器弹出（除了cs和eip）
    iret
    ;下面的不会执行只是为了防止任务没有正常切换做准备
    jmp $+2
    jmp $+2
    jmp $+2
    
    ret 