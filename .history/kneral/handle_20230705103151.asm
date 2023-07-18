[bits 32]
section .text
extern real_handle
extern handles_point
global handle_control
global handle_table



%macro handle_control 2
handle_control_%1 :

%ifn %2
push 0x20230412
%endif
push %1
jmp handle_entry
 
%endmacro 

handle_entry :
    push ds 
    push es
    push fs
    push gs
    pusha
    mov eax,[esp+12*4];由于对齐所以是12个
    push eax

    call [handles_point+eax*4]
    ;下面的过程对于任务切换来说永远也不会执行了
    ;对于系统调用等还是会运行的
    add esp,4
    popa
    pop gs
    pop fs
    pop es
    pop ds
    add esp,8;xxxxxxx如果这里不恢复到int指令调用时的栈，iret从寄存器获取的数据便会错乱，导致死循环，系统崩溃
    iret


    


handle_control 0x00,0
handle_control 0x01,0
handle_control 0x02,0
handle_control 0x03,0
handle_control 0x04,0
handle_control 0x05,0
handle_control 0x06,0
handle_control 0x07,0
handle_control 0x08,1
handle_control 0x09,0
handle_control 0x0a,1
handle_control 0x0b,1
handle_control 0x0c,1
handle_control 0x0d,1
handle_control 0x0e,1
handle_control 0x0f,0
handle_control 0x10,0
handle_control 0x11,1
handle_control 0x12,0
handle_control 0x13,0
handle_control 0x14,0
handle_control 0x15,0
handle_control 0x16,0
handle_control 0x17,0
handle_control 0x18,0
handle_control 0x19,0
handle_control 0x1a,0
handle_control 0x1b,0
handle_control 0x1c,0
handle_control 0x1d,0
handle_control 0x1e,0
handle_control 0x1f,0
handle_control 0x20,0
handle_control 0x21,0
handle_control 0x22,0
handle_control 0x23,0
handle_control 0x24,0
handle_control 0x25,0
handle_control 0x26,0
handle_control 0x27,0
handle_control 0x28,0
handle_control 0x29,0
handle_control 0x2A,0
handle_control 0x2B,0
handle_control 0x2C,0
handle_control 0x2D,0
handle_control 0x2E,0
handle_control 0x2F,0
handle_control 0x30,0
;1.没有将数据放在数据段
;2.表中存储数据要用写入命令，不然程序会认为是标签
section .data
handle_table :
    dd handle_control_0x00
    dd handle_control_0x01
    dd handle_control_0x02
    dd handle_control_0x03
    dd handle_control_0x04
    dd handle_control_0x05
    dd handle_control_0x06
    dd handle_control_0x07
    dd handle_control_0x08
    dd handle_control_0x09
    dd handle_control_0x0a
    dd handle_control_0x0b
    dd handle_control_0x0c
    dd handle_control_0x0d
    dd handle_control_0x0e
    dd handle_control_0x0f
    dd handle_control_0x10
    dd handle_control_0x11
    dd handle_control_0x12
    dd handle_control_0x13
    dd handle_control_0x14
    dd handle_control_0x15
    dd handle_control_0x16
    dd handle_control_0x17
    dd handle_control_0x18
    dd handle_control_0x19
    dd handle_control_0x1a
    dd handle_control_0x1b
    dd handle_control_0x1c
    dd handle_control_0x1d
    dd handle_control_0x1e
    dd handle_control_0x1f
    dd handle_control_0x20
    dd handle_control_0x21
    dd handle_control_0x22
    dd handle_control_0x23
    dd handle_control_0x24
    dd handle_control_0x25
    dd handle_control_0x26
    dd handle_control_0x27
    dd handle_control_0x28
    dd handle_control_0x29
    dd handle_control_0x2A
    dd handle_control_0x2B
    dd handle_control_0x2C
    dd handle_control_0x2D
    dd handle_control_0x2E
    dd handle_control_0x2F
    dd handle_control_0x30

        