#include "2.h"
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

int main(int argc, char *args[]){

    //assert(argc == 2);
    
    // #if defined RUN_TEST
    // #undef RUN_TEST
    // #endif 
    
    #ifdef RUN_TEST
    test_c_str_dec_bit_minus();
    #endif 

    return 0;
}