#include <stdio.h>
#include <stdlib.h>

typedef struct s0{
    int shade;
    int *shsp;
    char *shp;

    int (*mkshp) (int sh, int *shspp);
} s0;

#define _max_int_(a, b) (a > b ? a : b) 
#define _min_int_(a, b) (a < b ? a : b)
#define _abs_int_(i) (i > 0 ? i : -i)
#define _rmv_ext_(c) (exit(c))
#define _cat_str_dbl_(s0, s1) (s0#s1)
// #define _cat_str_mul_(s0, s1, ... ) (s0#s1#...)


int main(){

    const char *s0 = "000", *s1 = "asd";
    printf("%d\n", _cat_str_dbl_(12357852, 2));

    return 0; 
}