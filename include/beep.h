#ifndef BEEP_H
#define BEEP_H
#define beep_port 0x61
#define hz 1193182
#define beep hz/440

void start_beep(void);
#endif
