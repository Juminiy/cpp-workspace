#include "0.h"
#include "1.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <assert.h>

void is_same(float *num, float *num_comp){ 
    int comp_same = comp(FLOAT, num, num_comp);
    char *s_ = (char *)(malloc(BYTE_1 + 2));
    assert(s_);
    s_[0] = comp_same + '0', s_[1] = '\n', s_[2] = '\0';
    int s_byte = write(SYS_write, s_, BYTE_1 + 2);
    free(s_);
}

void* alloc_mem(size_t sz){
    void *ptr = mmap(NULL, sz, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
    if(ptr == (void*)-1){
        perror("mmap");
        return NULL;
    }
    int err = munmap(ptr, SIZE_1);
    if(err)
        perror("unmap");
    return ptr;
}

void emit_asm_to_mem(unsigned char *m){
    assert(m);
    unsigned char asm_[] = {
        0x48, 0x89, 0xf8,
        0x48, 0x83, 0xc0, 0x04,
        0xc3
    };
    memcpy(m, asm_, sizeof(asm_));
}

void run_asm_code(){
    void *m = alloc_mem(SIZE_1);
    assert(m);
    emit_asm_to_mem(m);
    jitfun func_ = m;
    printf("%ld\n", func_(2));
}

int fipippi_(int x, int *py, int **ppz){
    **ppz += 1;
    *py += 2;
    x += 3;
    return x + *py + **ppz;
}

void fmt_ppi(int **ppi){
    **ppi += 5;
}