#include <iostream>
#include <stack>
#include <vector>
#include <stddef.h>
#include "fg_function.h"
#include "itimer.h"
#define MAX_N 10005

std::vector<uint64_t> fs;
std::vector<uint64_t> gs;


uint64_t Lfg(int f, int n){
    if(f){
        if(fs[n])
            return fs[n];
        else 
            return fs[n] = (fs[n-1] = Lfg(1, n-1)) + (gs[n-2] = Lfg(0, n-2));
    } else{ 
        if(gs[n])
            return gs[n];
        else 
            return gs[n] = (fs[n+1] = Lfg(1, n+1)) + (gs[n-1] = Lfg(0, n-1));
    }
    return 0;
}

int Lfg_function(int f, int n){
    fs.assign(n+1, 0);
    gs.assign(n+1, 0);
    fs[0]=fs[1]=gs[0]=gs[1] = 1;
    return Lfg(f, n);
}


int Pfg_function(int f, int n){
    std::stack<fg*> stk;
    stk.push(makeFG(f, n));
    int ans = 0;
    while(!stk.empty()){
        fg * fgs = stk.top(); stk.pop();
        if(fgs->n <= 1){
            ans += 1;
        } else {
            if(!(fgs->f)){
                stk.push(makeFG(0, fgs->n-1));
                stk.push(makeFG(1, fgs->n+1));
            } else {
                stk.push(makeFG(0, fgs->n-2));
                stk.push(makeFG(1, fgs->n-1));
            }
        }
    }
    return ans;
}


int main(){

    int state_f = 1, num_n = 1; 
    iTimer *it = makeITimer();
    while(std:: cin >> state_f >> num_n){
        if(num_n < 22){
            if(state_f == 1){
            it = resetITimer(it);
            std::cout << "f(" << num_n << ") = " << f(num_n);
            it = updateITimer(it);
            std::cout << ", time = " << secondCount(it) << "s" << std::endl;
            } else {
                it = resetITimer(it);
                std::cout << "g(" << num_n << ") = " << g(num_n);
                it = updateITimer(it);
                std::cout << ", time = " << secondCount(it) << "s" << std::endl;
            }

            it = resetITimer(it);
            std::cout << "Stacked DFS = " << Pfg_function(state_f, num_n);
            it = updateITimer(it);
            std::cout << ", time = " << secondCount(it) << "s" << std::endl;
        }

        it = resetITimer(it);
        std::cout << "Memorized DFS = " << Lfg_function(state_f, num_n); 
        it = updateITimer(it);
        std::cout << ", time = " << secondCount(it) << "s" << std::endl;
    }
    return 0;
    
}