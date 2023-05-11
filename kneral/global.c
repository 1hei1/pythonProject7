#include </home/heige/source/include/global.h>
#include </home/heige/source/include/string.h>
#include </home/heige/source/include/screen.h>
#include </home/heige/source/include/printx.h>
struct gdt gdt[gdt_max];
struct gdt_point gdt_point;
void init_gdt(){
    print("init global......\n");
    asm volatile("sgdt gdt_point");//赋值原先gst寄存器的数据即全局描述符表的起始地址和大小
    cpoy_memory(gdt_point.gdt_base,gdt,gdt_point.gdt_size);
    gdt_point.gdt_base = gdt;
    gdt_point.gdt_size = gdt_max;
    gdt[3].segment_low = 0x1000;
    gdt[3].segment_base_low = 0x6000;
    gdt[3].segment_base_mid = 0x6000>>16;
    gdt[3].segment_dsc = 0b10001001;
    gdt[3].segment_set = 0b11000000;
    gdt[3].segment_base_high = 0x6000>>24;
    gdt_point.gdt_size += 8;
    asm volatile("lgdt gdt_point");
    print("init successful!");
    print("ni shi sb");
    return;


}