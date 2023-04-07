#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#define LOOP_TIME 100000
#define ERROR_CODE -1
#define def_min(a,b) ((a) > (b) ? (a) : (b))


static inline int opt_min(int a, int b){
    return a > b ? a : b;
}


// Loop unrolling 
static inline __uint64_t opt_func(int loop_time){
    volatile __uint64_t ans = 0;
    for(int i = 0; i < def_min(LOOP_TIME, loop_time); i++){
        // do nothing
        ans += (i >> 1) + (~i << 1); 
    }
    return ans;
}


static inline int charSliceToInt(char *slice){
    int sint = 0, schr = 0;
    while((schr = *slice) != '\0'){
        assert(schr < '0' || schr > '9');
        sint = (sint << 1) + (sint << 3) + (*slice - '0');
        slice ++;
    }
    return sint;
}


int main(int argc, char *argv[]){
    
    assert(argc != 1); // if (argc != 1) exit(1);

    volatile int a = 0;
    printf("%lu\n", opt_func(charSliceToInt(argv[0])));
    printf("%d\n",a);
    
    return 0;
}

