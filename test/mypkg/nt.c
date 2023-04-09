#include <stddef.h>
int main(void){
 int a __attribute__((unused)) =0, b=1, c=1;
 
 a = sizeof( c = ++b + 1);

 printf("%d\n%d\n%d\n", a, b, c);
 return 0;
}
