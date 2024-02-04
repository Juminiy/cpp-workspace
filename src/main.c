// #include "3.h"
// #include <sys/syscall.h>
// #include <unistd.h>
#include <stdio.h>
// #include <string.h>
// #include <assert.h>
// #include <stdlib.h>
// #include <time.h>
#include "5.h"

// x=4, py=&c, ppz=&py
int f(int x, int *py, int**ppz) {
    **ppz += 1;// stack(runf)->c = 5 
    *py += 2;// stack(runf)->c = 7
    x += 3;// x = 7
    return x + *py + **ppz; //21
}

void runf(){
    int c = 4;
    int *b = &c;
    int **a = &b;
    printf("%d\n", f(c,b,a));
}

int main(){

    test_xstrdup();
    // char * hello = "hello";
    // printf("%p\n",hello);
    return 0;
}