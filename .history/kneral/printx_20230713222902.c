#include </home/heige/source/include/printx.h>
#include </home/heige/source/include/screen.h>
#include </home/heige/source/include/math.h>
void printk(int cnt,...){
    char* args = &cnt;
    while(cnt--){
    args+=sizeof(char*);
    char * arg = args;


    screen_write((*arg));
    }



}


int print(char str[],...){
    int test = &str;
    char * p = str;

    char s = *p;
    for (;s;p++,s=*p){
         if(s=='\0'){
            break;
        }
        else if(s=='%'){

            s = *(p+1);
            switch (s)
            {
            case 'd':
                test+=4;
                int *dt = (test);
                int consult = *(dt);
                int remainder = consult;
                int consult_mid=1;
                int len=1;
                for(int i=consult/10;i!=0;i/=10){
                    len+=1;
                }
                
                char result[32];
                for(int i = 0;consult_mid!=0;i+=1,consult_mid=remainder/10,remainder=remainder%10){
                    result[i] = 48+consult_mid;
                    
                }
                result[len]=remainder+48;
                for(int i=1;len!=0;len--,i++){
                    screen_write(result[i]);
                }
                p+=1;
                
                break;
            
            default:
                break;
            }
            

        }
        else{
             screen_write(s);
         
        }
        
       



    }
    return 1;
    
}