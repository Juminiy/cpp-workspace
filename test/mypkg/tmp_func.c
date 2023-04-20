#include "tmp_func.h"
#include <stdlib.h>
#include <stdio.h>

int ssignal(int base, int bits){
    for(int i = 0; i < INT_32_BITS; i ++){
        if((1 << i) & bits) {
            base += ((1 << i) ^ i);
        }
    }
    return base;
}

int ssrun(int *base_ptr, int sz_n, int threads){
    for(int i = 0; i < threads; i ++){
        for(int j = 0; j < sz_n; j ++){
            base_ptr[j] += base_ptr[j + 1] + (1 << i);
        }
    }
    return base_ptr[sz_n-1];
}

sA* makesA(int a, int b){
    sA *sa = (sA*)(malloc(sizeof(sA)));
    sa->a = a, sa->b = b;
    return sa;
}

sB* makesB(sA *sa){
    sB *sb = (sB*)(malloc(sizeof(sB)));
    sb->sa = sa;
    return sb;
}

void delsA(sA *sa){
    if(sa) 
        free(sa);
    sa = NULL;
}

void delsB(sB *sb){   
    if(sb)
        free(sb->sa);
    if(sb &&sb->sa)
        sb->sa = NULL;
    free(sb);
}

void showsA(sA *sa){
    printf("addr[sA] = %p\n", sa);
}

void showsB(sB *sb){
    printf("addr[sB] = %p, addr[sA] = %p\n",sb, sb->sa);
}