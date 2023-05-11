#include </home/heige/source/include/math.h>
int square(int base,int power)
{
    int result;
    for(int i=0;i<power;i++)
    {
        result*=base;
    }
    return result;
}