#ifndef IO_H
#define IO_H

char inb(short  port);
short inw(short  port);

void outb(short  port,char data);
void outw(short  port, int data);



#endif