[bits 32]

extern init_kneral  ;声明函数在另一个文件里
global start
start:
    xchg bx,bx
    call init_kneral
    ;xchg bx,bx
    ;mov esp,0xa010测试各个寄存器在分页后是指向物理地址还是虚拟地址
    ;push eax
    ;push ebx

    xchg bx,bx
    ; mov ax,24
    ; ltr ax
    ; str ax
    ; push eax
    int 0x28
    ;xchg bx,bx
    jmp $
    int 0x20;
jmp $