

char * strands(char *A,char *B){
        int i=0;
        for(;*(A+i)!='\0';i++);
        for(int n=0;*(B+n)!='\0';n++){
            *(A+i+n) = *(B+n);
        }
        return A;

}

int main(){
    char a[] = "abcdefg";
    char b[] = "huighi";
    char *c = strands(a,b);
    printf(c);

}
