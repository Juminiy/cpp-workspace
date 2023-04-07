#include "2.h"
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

    
    // #if defined RUN_TEST
    // #undef RUN_TEST
    // #endif 
    
    #ifdef RUN_TEST
    assert(argc == 2);
    test_c_str_dec_plus_n_round(atoi(argv[1]));
    #endif 

    return 0;
}