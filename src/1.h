#ifndef _1_H
#define _1_H

#define BYTE_1 1 
#define SIZE_1 1024
#include <unistd.h>
#include <stddef.h>
#include <sys/syscall.h>
#include <stdlib.h>

typedef long (*jitfun)(long);

void is_same(float *, float *);
void* alloc_mem(size_t );
void emit_asm_to_mem(unsigned char *);
void run_asm_code();
int fipippi_(int , int *, int **);
void fmt_ppi(int **);




#endif 