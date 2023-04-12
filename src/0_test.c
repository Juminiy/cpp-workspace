#include "0.h"
#include <stdio.h>

#ifdef COMPILE_TEST
void test_c_type_byte(){
    printf("%ld\n", sizeof(long double));
    printf("%ld\n", sizeof(void));
}
#endif 