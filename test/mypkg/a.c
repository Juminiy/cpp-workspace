#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct sppa{
    int s :  7;
    int p1:  6;
    int p2:  6;// 32- 19 = 13;
    int a : 13;
} sppa;
void main(){
    sppa * sppa1 = (sppa*)(malloc(sizeof(sppa)));
    printf("%p\n", sppa1);
    char *openai_api_key = getenv("OPENAI_API_KEY");
    assert(openai_api_key);
    printf("%s\n", openai_api_key);
    printf("%d\n", 1<<1);
    free(sppa1);
}