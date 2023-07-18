#ifndef TIME_H
#include </home/heige/source/include/type.h>
#include </home/heige/source/include/io.h>

#define time_select 0x70
#define time_data 0x71

#define on 1
#define off 0

#define ms_500 0
#define ms_250 1
#define ms_125 2
#define ms_62 3
#define ms_31 4
#define ms_7 5
#define ms_4 6
#define ms_2 7
#define μs_976 8
#define μs_488 9
#define μs_244 10
#define μs_122 11


char get_s();
char get_minute();
char get_hour();
char get_year();
//设置时钟中断-------------产生周期性中断实现任务切换
void set_clock_interrupt(int divide,int on_off);
void delay(int ms);
#endif
