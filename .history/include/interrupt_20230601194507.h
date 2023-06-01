#ifndef INTERRUPT_H
#define INTERRUPT_H
#include </home/heige/source/include/type.h>
#include </home/heige/source/include/task_switch.h>
#define main_control_l 0x20
#define main_control_h 0x21
#define slice_control_l 0xa0
#define slice_control_h 0xa1
#define idt_size 256
struct idt{
    u16 offset_l;
    u16 selector;
    u8 keep0;
    u8 access;
    u16 offset_h;
} __attribute__((__packed__));
struct idt_point{
    u16 idt_sizes;
    u32 idt_address;
} __attribute__((__packed__));
 
struct handle_point{
    void* handle;
};

//第10位为if位
//启用sti
//关闭cli
//1110中断门
//1111陷阱们

void set_error(int vector);//异常处理函数
void set_handles(int vector,int handles_address);//普通处理函数

void interrupt_allow();//允许外中断
void interrupt_disalow();//不允许外中断
char interrupt_getstate();//获取外中断if状态
void stop_interrupt();//停止外中断
void set_priority(char irq);//设置中断特权级
void init_control();//初始化中断控制器
void init_idt();//初始化中断向量表
void init_interrupt();//初始化中断
void task2();


#endif
