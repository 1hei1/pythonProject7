#ifndef CLOCK_H
#define clock_h
#include </home/heige/source/include/type.h>
#define clock_1 0x40
#define clock_2 0x41
#define clock_3 0x42
#define clock_control 0x43


// ## 8253 控制字

// 控制字寄存器，端口号 0x43，是 8 位寄存器，控制字寄存器也成为模式控制寄存器，用于指定计数器的 工作方式、读写格式 及 数制。

// 控制字结构：

// | 7   | 6   | 5   | 4   | 3   | 2   | 1   | 0   |
// | --- | --- | --- | --- | --- | --- | --- | --- |
// | SC1 | SC0 | RL1 | RL0 | M2  | M1  | M0  | BCD |


// - SC(Select Counter) 0 ~ 1：计数器选择位
//     - 00 计数器 0
//     - 01 计数器 1
//     - 10 计数器 2
//     - 11 无效
// - RL(Read Load) 0 ~ 1：读写操作位
//     - 00 锁存数据，供 CPU 读
//     - 01 只读写低字节
//     - 10 只读写高字节
//     - 11 先读写低字节，后读写高字节
// - M (Mode) 0 ~ 2：模式选择
//     - 000：模式 0
//     - 001：模式 1
//     - x10：模式 2
//     - x11：模式 3
//     - 100：模式 4
//     - 101：模式 5
// - BCD：(Binary Coded Decimal) 码
//     - 0 表示二进制计数器
//     - 1 二进制编码的十进制计数器


void set_clock_control(u8 setting);//设置时钟控制位
void set_clock_startnmb(u8 clock_nmb,u16 start_number);//设置时钟起始值
u16 get_clock(u8 clock_nmb,u8 setting);//获取时钟当前的值


#endif