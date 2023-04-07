#include "2.h"
#include "1.h"
#include "0.h"
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
    test_c_type_byte();
    #endif 

    return 0;
}