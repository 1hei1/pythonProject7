#include </home/heige/source/include/string.h>



void cpoy_memory(char *src,char *dst,int size){
    int i = 0;
    for(;i<size;i++){
        *dst++=*src++;

    };

}

char * strand(char *A,char *B){
        int i=0;
        for(;*(A+i)!='\0';i++);
        for(int n=0;*(B+n)!='\0';n++){
            *(A+i+n) = *(B+n);
        }
        return A;

};