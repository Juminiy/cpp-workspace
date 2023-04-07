#include <stdio.h>
#include <sys/types.h>

#define _ERROR_ -1
// char *str1 , pointer is stored in current stack section, content is stored in code section,or malloc() to store in the heap section.
// char str2[], char array is stored in current stack section.

struct in_align{
    int a;
    char b;
    float c;
    char *d;
} in_align;

struct __attribute__ ((__packed__)) non_align{
    int a;  //  4
    char b; // 1
    float c;// 4
    char *d;// 8
} non_align;

struct bit_fields{
    unsigned int bit1: 16;
    unsigned int bit2: 8;
    unsigned int bit3: 4;
    unsigned int f1: 1;
    unsigned int f2: 1;
    unsigned int f3: 1;
    unsigned int f4: 1;
} bf;

int main(){

    printf("%ld\n", sizeof(in_align));

    printf("%ld\n", sizeof(non_align));

    printf("%ld\n",sizeof(bf));

    return 0;

}