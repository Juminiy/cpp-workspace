#include "3.h"
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

    
    // #if defined RUN_TEST
    // #undef RUN_TEST
    // #endif 
    
    #ifdef RUN_TEST
    test_c_str_int_aligned();
    #endif 

    double _xma, _xmb;
    scanf("%lf %lf", &_xma, &_xmb);
    printf("%.2f %.2f\n", _xma, _xmb);
    return 0;
}