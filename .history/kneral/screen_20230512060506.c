#include </home/heige/source/include/screen.h>
extern pos;
void roll_one(){
    int n = (pos/160);//记录行数
    int x = (pos%160);//记录不满一行的那行
    int i = 160;//记录行宽
    int s = 0;
    int o = 0;//记录一行的第几个
    if (x>0)
    {
        n++;
    }
    
    while (n--)
    {   
        while (i--)
        {   if (s>=4000-160)
        {
            break;
        }
        
           *((char*)(s+0xb8000)) = *((char*)(s+0xb8000+160)); 
           s+=1;
        }

        i=160;
        
    }
    int m=160;
    while (m--)
    {
        *((char*)(s+0xb8000+m)) = 32;
        m--;
        *((char*)(s+0xb8000+m)) = 4;

    }
    
}




void clear_screen()
{   //char* sc_st = screen_start;
//     int sc_m = screen_m;
    while(sc_m--){
        (*sc_st++) = 6;
    }
    *sc_st = screen_start;
}




void clean_line(pos){
    int n = pos/160;
    char* c = (n+1)*160;
    int m=160;
    while (m--)
    {
        *(c)++ = 2;

    }
    
}

void get_mouse(){
    outb(adder,cursor_h);
    y = inb(data);
    outb(adder,cursor_l);
    x = inb(data);
    pos = x+y*80;
}


void set_mouse(){
    
   
    outb(adder,cursor_h);
    outb(data,(pos/2)>>8&0xff);
    outb(adder,cursor_l);
    outb(data,(pos/2)&0xff);

}


void screen_write(char Special_characters){

    switch (Special_characters)
    {
    case '\n':
        x = pos%screen_x;
        pos+=(screen_x-x);
        set_mouse();
        break;
    case 127:
        pos-=2;
        set_mouse();
        char * ad = pos+screen_start;
        *ad = 0;
        *(ad+1) = 0;
        break;
        

    default:
        
        char* ad0 = (screen_start+pos);
        *ad0 = Special_characters;
        *(ad0+1) = 6;
        pos +=2;
        
            if (pos >=4000 )
             {  //clean_line();
                roll_one();
                clean_line(pos);
                pos -= 160;
             }
             set_mouse();
        
        break;
    }

}

