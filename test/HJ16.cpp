#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct vpq{
    int v,p,q,vp;
    vpq(){

    }
    vpq(int _v,int _p,int _q){
        v = _v, p = _p, vp = _v*_p, q = _q;
    }
} vpq;
int main(){

    int n,m;
    cin >> n >> m;
    vector<vpq> v(m, vpq());
    vector<vector<int>> group(m+1);
    int _v,_p,_q;
    for(int i=0;i<m;i++){
        cin >> _v >> _p >> _q;
        v[i] = vpq(_v,_p,_q);
        if(_q){
            group[_q-1].push_back(i);
        }
    }
    vector<int> f(n+1, 0);
    int tv = 0;
    for(int i=0;i<m;i++){
        for(int j=n;j>=v[i].p;j--){
            if(!v[i].q)
                f[j] = max(f[j], f[j-v[i].v]+v[i].vp);
            else {
                int main_prod = v[i].q - 1;
                int sz = group[main_prod].size();
                if(sz == 1){
                    if(j>=v[i].v+v[main_prod].v) 
                        f[j] = max(f[j], f[j-v[i].v-v[main_prod].v]+v[i].vp+v[main_prod].vp);
                } else if(sz == 2){
                    int ii = group[main_prod][0],ij = group[main_prod][1];
                    if(j>=v[ij].v+v[ii].v+v[main_prod].v)
                        f[j] = max(f[j], f[j-v[ij].v-v[ii].v-v[main_prod].v]+v[ij].vp+v[ii].vp+v[main_prod].vp);
                }
            } 
        }
    }

    cout << f[n] << std::endl;

    return 0;
}