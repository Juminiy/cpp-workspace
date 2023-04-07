#include <iostream>
#include <mutex>
#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <list>

template <typename T>
void printVector(std::string vn, std::vector<T> &v){
    assert(v.size());
    __SIZE_TYPE__ it = 0;
    std::cout << vn << "[";
    for(; it < v.size()-1; it ++){
        std::cout << v[it] << ", ";
    }
    std::cout << v[it]<< "]" << std::endl;
}

typedef struct alignas(std::max_align_t) align_ptr{
    char a;
    int  b;
    double c;
    char * d;
} aptr;

int main(int argc, char *argv[]){

    std::vector <int> l = {1, 4, 100};
    std::sort (l.begin(), l.end(), [](int a, int b) {
        return a - b ;
    });
    printVector("l" ,l);
    return 0;
}