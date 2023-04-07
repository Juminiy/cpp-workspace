#ifndef __TMP_FUNC_H__
#define __TMP_FUNC_H__
#include "defs.h"

int ssignal(int, int);
int ssrun(int*, int, int);

typedef struct structA{
    int a,b;
} sA;

typedef struct structB{
    sA *sa;
} sB;

sA *makesA(int, int);
sB *makesB(sA *);
void delsA(sA *);
void delsB(sB *);
void showsA(sA *);
void showsB(sB *);

#endif 