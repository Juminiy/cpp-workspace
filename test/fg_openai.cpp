#include <stack>

int f1(int n){
    if(n<=1) return 1;
    int fn = 1, fn_1 = 1, gn_1 = 1, gn_2 = 1;
    for(int i=2; i<=n; i++){
        int tmp = fn;
        fn = fn_1 + gn_2;
        gn_2 = gn_1;
        gn_1 = tmp + gn_1;
        fn_1 = tmp;
    }
    return fn;
}

int g1(int n){
    if(n<=1) return 1;
    int fn_1 = 1, fn = 1, gn = 1, gn_1 = 1;
    for(int i=2; i<=n; i++){
        int tmp = gn;
        gn = gn_1 + fn_1;
        fn_1 = fn;
        fn = fn_1 + tmp;
        gn_1 = tmp;
    }
    return gn;
}



int f2(int n){
    if(n<=1) return 1;
    std::stack<int> stack;
    stack.push(n);
    int result = 0;
    while(!stack.empty()) {
        int cur = stack.top();
        stack.pop();
        if(cur <= 1) {
            result += 1;
        } else {
            stack.push(cur-1);
            stack.push(cur-2);
        }
    }
    return result;
}

int g2(int n){
    if(n<=1) return 1;
    std::stack<int> stack;
    stack.push(n);
    int result = 0;
    while(!stack.empty()) {
        int cur = stack.top();
        stack.pop();
        if(cur <= 1) {
            result += 1;
        } else {
            stack.push(cur+1);
            stack.push(cur-1);
        }
    }
    return result;
}
