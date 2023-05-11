[bits 32]
section .text
global set_cr0 ;如果不设置就找不到这个函数
set_cr0 :
    push ebp
    mov ebp,esp
    mov eax,[ebp+8]
    mov ebx,cr0
    or ebx,eax
    mov cr0,ebx
    xchg bx,bx
    leave
    ret

global set_cr3
set_cr3 :
    push ebp
    mov ebp,esp
    mov eax,[ebp+8]
    mov ebx,cr3
    or ebx,eax
    mov cr3,ebx
    xchg bx,bx
    leave
    ret
