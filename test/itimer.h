#include <time.h>
#include <malloc.h>
#include <assert.h>

typedef struct iTimer{
    clock_t *current, *start;
} iTimer;

iTimer* makeITimer(){
    iTimer *it = (iTimer*)(malloc(sizeof(iTimer))); 
    it->start = (clock_t*)(malloc(sizeof(clock_t)));
    it->current = (clock_t*)(malloc(sizeof(clock_t)));
    return it;
}

iTimer* updateITimer(iTimer *it){
    *(it->current) = clock();
    return it;
}

iTimer* resetITimer(iTimer *it){
    
    *(it->current) = *(it->start) = clock();
    
    return it;
}

double secondCount(iTimer *it){
    assert(it); // if (it == NULL) exit(1);
    assert(it->start);
    assert(it->current);
    double during_second = (float(*(it->current))*1.0 - float(*(it->start))*1.0) / CLOCKS_PER_SEC*1.0 ;
    return during_second;
}

