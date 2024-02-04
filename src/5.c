#include "5.h"
#include <stdio.h>
#include <stdlib.h>

char *
xstrdup(char * args)
{
    char *p = strdup(args);
    if (!p)
        exit(1);
    return p;
}

void test_xstrdup(){
    char *s = "hello world!";
    printf("%p\n", s);
    printf("%p\n", xstrdup(s));
    free(s);
}