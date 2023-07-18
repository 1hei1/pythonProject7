[bits 32]

.text 
global running_task
running_task:
    mov eax,esp
    and eax,0xfffff000;
    ret