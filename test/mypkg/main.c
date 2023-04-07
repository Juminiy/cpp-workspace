#include "defs.h"
#include "tmp_func.h"
#include <stdio.h>

int main(){

    #ifdef ENV_PROD
    sA * sa = makesA(1, 2);
    sB * sb = makesB(sa);
    showsA(sa);
    showsB(sb);
    // delsA(sa);
    delsB(sb);
    showsA(sa);
    showsB(sb);
    #endif 
    
    #ifdef PARM1
    printf("%d\n",PARM1);
    #endif 

    #ifdef PARM2
    printf("%d\n",PARM2);
    #endif

    return 0;
}