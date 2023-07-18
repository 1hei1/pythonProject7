[bits 32]
section .text
global set_memory_char ;如果不设置就找不到这个函数
set_memory_char :
    push ebp
    mov ebp,esp
    xor eax,eax
    mov eax,[ebp+8]
    mov edx,[ebp+12]
    mov [eax],dl
    leave 
    ret
global set_memory_short
set_memory_short :
    push ebp
    mov ebp,esp
    xor eax,eax
    mov eax,[ebp+8]
    mov edx,[ebp+12]
    mov [eax],dx
    leave 
    ret
global set_memory_int
set_memory_int :
    push ebp
    ;xchg bx,bx
    mov ebp,esp
    xor eax,eax
    mov eax,[ebp+8]
    mov edx,[ebp+12]
    mov [eax],edx
    leave 
    ret   
global set_memory_page
set_memory_page:
    push ebp

    mov ebp,esp
    xor eax,eax
    xchg bx,bx
    mov ecx,[ebp+8];每次复制一个页
    shl ecx,12
    ;设置循环次数
    mov eax,[ebp+12];目标地址
    mov ebx,[ebp+16];原地址


    
    xunhuan :

    mov edx,[ebx]
    mov [eax],edx
    inc eax
    inc ebx
    sub ecx
    jz xunhuan

    pop ebx
    leave
    ret
