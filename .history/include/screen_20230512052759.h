#ifndef SCREEN_H
#define SCREEN_H

#define screen_start 0xb8000 //屏幕的起始位置
#define screen_m 4000       //显存大小
#define adder 0x3d4     //寄存器的地址端
#define data 0x3d5       //寄存器的数据端
#define cursor_h 0xe      // 光标位置
#define cursor_l 0xf        //高位  光标一行按80个字符，输入输出时一行是80个字符
#define screen_x 160        //屏幕的宽度
#define screen_y 25         //屏幕的高度

void clear_screen();//清空屏幕
void set_mouse();//设置鼠标的位置
void get_mouse();//获取鼠标的位置
void screen_write(char Special_characters);//屏幕写特殊字符
static int pos=0; //记录光标的内存位置
static char *sc_st = (char*)screen_start;//内存的起始位置
void roll_one();
static int sc_m = screen_m;//显存的大小
static int x,y;//光标的x,y坐标


#endif