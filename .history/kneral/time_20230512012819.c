#include </home/heige/source/include/time.h>
#include </home/heige/source/include/io.h>
#include </home/heige/source/include/printx.h>
#include </home/heige/source/include/math.h>
static char slreg[0x33]={
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50
};//时钟寄存器列表
void get_s()
{
    outb(time_select,slreg[0]+128);
    char s = inb(time_data);
    s = (s&0xf)+(s>>4)*10;
    print("now s is %d \n",s);
}

void get_minute()
{
    outb(time_select,slreg[2]);
    char s = inb(time_data);
     s = (s&0xf)+(s>>4)*10;
    print("now minute is %d \n",s);
}
void get_hour()
{
    outb(time_select,slreg[4]);
    char s = inb(time_data);
     s = (s&0xf)+(s>>4)*10;
    print("now hour is %d \n",s);
}
void get_year()
{
    outb(time_select,slreg[9]);
    char s = inb(time_data);
     s = (s&0xf)+(s>>4)*10;
    outb(time_select,0x32);
    char c = inb(time_data);
     c = (c&0xf)+(c>>4)*10;
    print("now s is%d%d \n",c,s);
   

}

void get_date()
{
    char year_h,year_l,mouth,hour,minute,s;
        outb(time_select,0x32);
    year_h = inb(time_data);
        outb(time_select,slreg[9]+128);
    year_l = inb(time_data);
        outb(time_select,slreg[8]+128);
    mouth = inb(time_data);
        outb(time_select,slreg[4]+128);
    hour = inb(time_data);
        outb(time_select,slreg[2]+128);
    minute = inb(time_data);
        outb(time_select,slreg[0]+128);
    s = inb(time_data);

        year_h = (year_h&0xf)+(year_h>>4)*10;
              year_l = (year_l&0xf)+(year_l>>4)*10;
                    mouth = (mouth&0xf)+(mouth>>4)*10;
                         hour = (hour&0xf)+(hour>>4)*10;
                             minute = (minute&0xf)+(minute>>4)*10;
                                     s = (s&0xf)+(s>>4)*10;
    print("now date is(year/mouth/hour/minute/second): %d%d-%d-%d-%d-%d",year_h,year_l,mouth,hour,minute,s);
}