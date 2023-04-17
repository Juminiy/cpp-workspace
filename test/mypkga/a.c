#include <stdio.h>

// run error
void re_0(){
    char *p = NULL;
    *p = 'A';
    printf("%s\n", p);
}

// run beyond imagination -> rbi
void rbi_0(){
    printf("%d\n", sizeof(int) > -1);
}

void rbi_1(){
    int a, b = 1, c = 1;
    a = sizeof(c = ++b + 1);
    printf("a = %d, b = %d, c = %d\n", a, b, c);
}

// vague between cc
void vbc_0(){
    float a = 0.1;
    double b = 0.1;
    printf("%d\n%d\n", a == 0.1, b == 0.1);
}

// 10 GB = 10 * (1 << 30) B = (1<<3+1<<1)*(1<<30) B = (1<<33 + 1<<31) B = 
// 0b10 10000000 00000000 00000000 00000000
// 0x2 80 00 00 00
// ULI_MAX = (1 << 32) - 1  


void foo(int *i1, int *i2, int *res){
    for(int i=0;i<10;i++)
        *res += *i1 + *i2;
}
int main(void){

    


    return 0;
}