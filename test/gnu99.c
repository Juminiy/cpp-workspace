// %c %d %f %p %s  
// %e %E %Lf %Le 
// %g %G
// %a %A
// %ho %hd %hx %hu 
// %lo %ld %lx %lu 
// %llo %lld %llx %llu
// %n %i %o %x %u %zd %%
#include <stdio.h>
#include <limits.h>
// \a \b \f \n \r \t \v \0 
int main(){

    // printf("a, %ld\a\n", sizeof(char));
    // printf("b, %ld\b\n", sizeof(short int));
    // printf("r, %ld\r\n", sizeof(int));
    // printf("t, %ld\t\n", sizeof(long int));
    // printf("v, %ld\v\n", sizeof(long long int));
    // printf("0, %ld\n", sizeof(int ***));

    printf("%d\n", (0.1 + 0.2 ) == 0.3  );

    return 0;
}
