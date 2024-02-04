#ifndef _1_HPP
#define _1_HPP

#include <map>
#include <omp.h>

class IntMap {
    std::map<int,int> m;
public:
    void run();
};

IntMap::run(){
    #pragma openmp parallel for 
    for (int i = 0; i < 1<<32; i++) {
        m[i] = i >> 1;
    }
}




#endif 
