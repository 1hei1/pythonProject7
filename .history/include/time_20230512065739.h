#ifndef TIME_H
#include </home/heige/source/include/type.h>
#include </home/heige/source/include/io.h>

#define time_select 0x70
#define time_data 0x71

void get_s();
void get_minute();
void get_hour();
void get_year();
//设置时钟中断-------------产生周期性中断实现任务切换
void set_clock_interrupt(int divide,int on_off);
#endif
