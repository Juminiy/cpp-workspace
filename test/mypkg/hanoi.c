#include <stdio.h>
#include <malloc.h>
#define FROM 'a'
#define VIA_ 'b'
#define TO__ 'c'


static inline void 
debugPath(char a, char b)
{
    printf("%c -> %c\n", a, b);
    return;
}

void RHanoi(int n, char from, char via, char to)
{
    if(n == 1){
        debugPath(from, to);
        return;
    } 
    RHanoi(n-1, from, to, via);
    RHanoi(1, from, via, to);
    RHanoi(n-1, via, from, to);
    return;
}

typedef struct hanoi{
    int n;
    char from, via, to;
} hanoi;

hanoi* makeHanoi(int n, char from, char via, char to){
    hanoi *h = (hanoi*)(malloc(sizeof(hanoi)));
    h->from = from, h->via = via, h->to = to;
    h->n = n;
    return h;
}

void delHanoi(hanoi *h){
    if(h)
        free(h);
}

typedef struct hstack{
    struct hstack *next;
    hanoi *h; 
} hstack;

hstack* makeHS(hanoi *h){
    hstack *hs = (hstack*)(malloc(sizeof(hstack)));
    hs->h = h;
    hs->next = NULL;
    return hs;
}
void delHS(hstack *hs){
    if(hs){
        delHanoi(hs->h);
        free(hs);
    }
}
void delLinkHS(hstack *hs){
    hstack *tmp;
    while(hs){
        tmp = hs->next;
        delHS(hs);
        hs = tmp;
    }
}

hstack* pushHS(hstack *hs, hanoi* h){
    if(!hs){
        return makeHS(h);
    }
    hstack *newHead = makeHS(h);
    newHead->next = hs;
    return newHead;
}

hstack* popHS(hstack *hs){
    if(!hs){
        return NULL;
    }
    hstack *newHead = hs->next;
    // delHS(hs);
    return newHead;
}

hanoi* topHS(hstack *hs){
    if(hs){
        return hs->h;
    }
    return NULL;
}

int emptyHS(hstack *hs){
    return hs == NULL;
}


void PHanoi(int n, char from, char via, char to)
{
    hstack *hs = NULL;
    hs = pushHS(hs, makeHanoi(n, from, via, to));
    while(!emptyHS(hs)){
        hanoi *h = topHS(hs);
        hs = popHS(hs);
        if(h->n == 1){
            debugPath(h->from, h->to);
        } else {
            hs = pushHS(hs, makeHanoi(h->n-1, h->via, h->from, h->to));
            hs = pushHS(hs, makeHanoi(1, h->from, h->via, h->to));
            hs = pushHS(hs, makeHanoi(h->n-1, h->from, h->to, h->via));
        }
    }
}

int main(int argc, char *argv[]){
    PHanoi(3, FROM, VIA_, TO__);
    return 0;
}