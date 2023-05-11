build := ../build
boot := ../boot
kneral := ../kneral
entrypoit :=0x10000

canshu := -m32
canshu += -nostdinc
canshu += -nostdlib
canshu += -fno-pic
canshu += -fno-pie
canshu += -fno-builtin
canshu += -fno-stack-protector
canshu := $(strip $(canshu))
debug += -g
include += -I 


$(build)/boot/%.bin : $(boot)/%.asm
	mkdir -p $(build)/boot/

	nasm -f bin $< -o $@

$(build)/kneral/%.o : $(kneral)/%.asm
	mkdir -p $(build)/kneral/
	nasm -f elf32 $< -o $@ 

$(build)/kneral/%.o : $(kneral)/%.c
	mkdir -p $(build)/kneral/
	gcc $(canshu) $(debug) $(include)../include -c $< -o $@

$(build)/kneral/kneral.bin : $(build)/kneral/kneral.o \
	$(build)/kneral/main.o \
	$(build)/kneral/io.o \
	$(build)/kneral/screen.o \
	$(build)/kneral/printx.o \
	$(build)/kneral/string.o \
	$(build)/kneral/global.o \
	$(build)/kneral/interrupt.o \
	$(build)/kneral/handle.o \
	$(build)/kneral/clock.o \
	$(build)/kneral/beep.o \
	$(build)/kneral/time.o \
	$(build)/kneral/math.o \
	$(build)/kneral/direct_handle_memory.o \
	$(build)/kneral/memory.o \
	$(build)/kneral/setcr0_cr2_cr3.o \

	ld -m elf_i386 -static $^ -o $@ -Ttext $(entrypoit)

$(build)/system.bin : $(build)/kneral/kneral.bin

	objcopy -O binary $< $@

main.s : $(kneral)/main.c 
	gcc -S -g -m32 $< -o main.s

$(build)/master.img : $(build)/boot/boot.bin \
	$(build)/boot/loader.bin \
	$(build)/kneral/kneral.bin \
	$(build)/system.bin \


	yes | bximage -q -hd=16 -func=create -sectsize=512 -imgmode=flat $(build)/master.img
	dd if=$(build)/boot/boot.bin of=$(build)/master.img bs=512 count=1 conv=notrunc
	dd if=$(build)/boot/loader.bin of=$(build)/master.img bs=512 count=4 seek=2 conv=notrunc
	dd if=$(build)/system.bin of=$(build)/master.img bs=512 count=200 seek=10 conv=notrunc


.PHONY: clean
clean :
	rm -r $(build)
	

.PHONY : bochs
bochs :$(build)/master.img
	bochs -q
qemu :$(build)/master.img
	qemu-system-i386 \
	-m 32M \
	-boot c \
	-drive file=$<,if=ide,index=0,media=disk,format=raw \
	-audiodev pa,id=hda \
	-machine pcspk-audiodev=hda \
	
qemug :$(build)/master.img
	qemu-system-i386 \
	-s -S \
	-m 32M \
	-boot c \
	-hda $<

test : main.s