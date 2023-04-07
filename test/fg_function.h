#ifndef __FG_FUNCTION__
#define __FG_FUNCTION__
#include <malloc.h>

int f(int);
int g(int);


int f(int n){
    if(n<=1) return 1;
    return f(n-1) + g(n-2);
}

int g(int n){
    if(n<=1) return 1;
    return f(n+1) + g(n-1);
}

typedef struct fg_state{ 
    int f, n;
} fg;

fg* makeFG(int f, int n){
    fg * fgs = (fg*)(malloc(sizeof(fg)));
    fgs->f = f, fgs->n = n;
    return fgs;
}
void delFG(fg *fgs){
    if(fgs)
        free(fgs);
}

#endif 