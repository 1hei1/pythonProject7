%line 1+1 handle.asm
[bits 32]
[section .text]
[extern real_handle]
[global handle_control]
[global handle_table]


%line 17+1 handle.asm

handle_entry :
 push ds
 push es
 push fs
 push gs
 pusha
 mov eax,[esp+9*4]
 push eax
 call [handles_point+eax*4]
 add esp,4
 popa
 pop gs
 pop fs
 pop es
 pop ds





%line 9+1 handle.asm
handle_control0x00 :

push 20230412

push 0x00
jmp handle_entry

%line 9+1 handle.asm
handle_control0x01 :

push 20230412

push 0x01
jmp handle_entry

%line 9+1 handle.asm
handle_control0x02 :

push 20230412

push 0x02
jmp handle_entry

%line 9+1 handle.asm
handle_control0x03 :

push 20230412

push 0x03
jmp handle_entry

%line 9+1 handle.asm
handle_control0x04 :

push 20230412

push 0x04
jmp handle_entry

%line 9+1 handle.asm
handle_control0x05 :

push 20230412

push 0x05
jmp handle_entry

%line 9+1 handle.asm
handle_control0x06 :

push 20230412

push 0x06
jmp handle_entry

%line 9+1 handle.asm
handle_control0x07 :

push 20230412

push 0x07
jmp handle_entry

%line 9+1 handle.asm
handle_control0x08 :

push 20230412

push 0x08
jmp handle_entry

%line 9+1 handle.asm
handle_control0x09 :

push 20230412

push 0x09
jmp handle_entry

%line 9+1 handle.asm
handle_control0x0a :

push 20230412

push 0x0a
jmp handle_entry

%line 9+1 handle.asm
handle_control0x0b :

push 20230412

push 0x0b
jmp handle_entry

%line 9+1 handle.asm
handle_control0x0c :

push 20230412

push 0x0c
jmp handle_entry

%line 9+1 handle.asm
handle_control0x0d :

push 20230412

push 0x0d
jmp handle_entry

%line 9+1 handle.asm
handle_control0x0e :

push 20230412

push 0x0e
jmp handle_entry

%line 9+1 handle.asm
handle_control0x0f :

push 20230412

push 0x0f
jmp handle_entry

%line 9+1 handle.asm
handle_control0x10 :

push 20230412

push 0x10
jmp handle_entry

%line 9+1 handle.asm
handle_control0x11 :

push 20230412

push 0x11
jmp handle_entry

%line 9+1 handle.asm
handle_control0x12 :

push 20230412

push 0x12
jmp handle_entry

%line 9+1 handle.asm
handle_control0x13 :

push 20230412

push 0x13
jmp handle_entry

%line 9+1 handle.asm
handle_control0x14 :

push 20230412

push 0x14
jmp handle_entry

%line 9+1 handle.asm
handle_control0x15 :

push 20230412

push 0x15
jmp handle_entry

%line 9+1 handle.asm
handle_control0x16 :

push 20230412

push 0x16
jmp handle_entry

%line 9+1 handle.asm
handle_control0x17 :

push 20230412

push 0x17
jmp handle_entry

%line 9+1 handle.asm
handle_control0x18 :

push 20230412

push 0x18
jmp handle_entry

%line 9+1 handle.asm
handle_control0x19 :

push 20230412

push 0x19
jmp handle_entry

%line 9+1 handle.asm
handle_control0x1a :

push 20230412

push 0x1a
jmp handle_entry

%line 9+1 handle.asm
handle_control0x1b :

push 20230412

push 0x1b
jmp handle_entry

%line 9+1 handle.asm
handle_control0x1c :

push 20230412

push 0x1c
jmp handle_entry

%line 9+1 handle.asm
handle_control0x1d :

push 20230412

push 0x1d
jmp handle_entry

%line 9+1 handle.asm
handle_control0x1e :

push 20230412

push 0x1e
jmp handle_entry

%line 9+1 handle.asm
handle_control0x1f :

push 20230412

push 0x1f
jmp handle_entry

%line 70+1 handle.asm



[section .data]
handle_table :
 dd handle_control0x00
 dd handle_control0x01
 dd handle_control0x02
 dd handle_control0x03
 dd handle_control0x04
 dd handle_control0x05
 dd handle_control0x06
 dd handle_control0x07
 dd handle_control0x08
 dd handle_control0x09
 dd handle_control0x0a
 dd handle_control0x0b
 dd handle_control0x0c
 dd handle_control0x0d
 dd handle_control0x0e
 dd handle_control0x0f
 dd handle_control0x10
 dd handle_control0x11
 dd handle_control0x12
 dd handle_control0x13
 dd handle_control0x14
 dd handle_control0x15
 dd handle_control0x16
 dd handle_control0x17
 dd handle_control0x18
 dd handle_control0x19
 dd handle_control0x1a
 dd handle_control0x1b
 dd handle_control0x1c
 dd handle_control0x1d
 dd handle_control0x1e
 dd handle_control0x1f


