#include "3.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef COMPILE_TEST

void test_c_str_int_aligned(){
    c_str_int *i0 = (c_str_int*)(malloc(sizeof(c_str_int)));
    printf("size = %ld\n", sizeof(c_str_int));
    printf("__self = %p\n__hex = %p\nval_sz = %p\n___val = %p\n", i0, &(i0->hex), &(i0->val_sz), &(i0->val));
}

void test_c_str_int_initial(){

}

#endif 