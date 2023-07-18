#ifndef TIME_H
#include </home/heige/source/include/type.h>
#include </home/heige/source/include/io.h>

#define time_select 0x70
#define time_data 0x71

#define on 1
#define off 0

char get_s();
char get_minute();
char get_hour();
char get_year();
//设置时钟中断-------------产生周期性中断实现任务切换
void set_clock_interrupt(int divide,int on_off);
void delay(int delay);
#endif
