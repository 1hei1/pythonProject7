[bits 32]
section .text
extern task_table_pointers
global task_change
task_change :
    mov al,0xc
    mov dx,0x70
    out dx,al
    in al,dx
    call [task_table_pointers]
    jmp $+2
    jmp $+2
    jmp $+2
    
    iret 