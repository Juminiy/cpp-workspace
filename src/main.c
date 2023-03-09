#include "defs.h"
#include "tmp_func.h"
#include <stdio.h>

int main(){

    sA * sa = makesA(1, 2);
    sB * sb = makesB(sa);
    showsA(sa);
    showsB(sb);
    // delsA(sa);
    delsB(sb);
    showsA(sa);
    showsB(sb);

    return 0;
}