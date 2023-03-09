#include <cstdio>
#include <algorithm>

typedef struct pair{
    int k,v;
    pair(){

    }
    pair(int _k, int _v){
        k = _k, v = _v; 
    }
    bool operator < (pair a){
        return k < a.k;
    }
} pr;



int main() {
    int n, k, v, l = 0, f = 0;
    scanf("%d",&n);
    pr pir[501];
    for(int i=0;i<n;i++){
        scanf("%d %d",&k, &v);
        for(int j=0;j<l;j++){
            if(pir[j].k == k){
                pir[j].v += v;
                f = 1;
                break;
            }
        }
        if(f){
            f = 0;
        } else {
            pir[l++] = pair(k, v);
        }
    }
    std::sort(pir, pir+l);
    for(int i=0;i<l;i++){
        printf("%d %d\n",pir[i].k, pir[i].v);
    }
    return 0;
}