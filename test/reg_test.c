// #include <unistd.h>
// #include <sys/syscall.h>
#include <stdio.h>
// x64 intel cpu, linux5.19, gcc11.3.0
int arr_param(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n){return a+n;}
// FF FF FF FF >> 24
char char_param(long long a, long long b){return (a+b)>>(0x18);}
long long ll_param(){}

void main(){
    // 96 = 0x60
    // syscall(SYS_writev, 1, char_param(0xFFFFFFFF, 0x0), 2); 
    printf("%c\n", char_param(0x60000000, 0));
    // arr_param(1,2,3,4,5,6,7,8,9,10,11,12,13,14);
}