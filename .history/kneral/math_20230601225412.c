#include </home/heige/source/include/math.h>
#include </home/heige/source/include/time.h>
int square(int base,int power)
{
    int result;
    for(int i=0;i<power;i++)
    {
        result*=base;
    }
    return result;
}


char random(int base,int top){
    char time = get_s();
    time = time/10;
    char result = ((top-base)/9)*time+base;
    return result;
}