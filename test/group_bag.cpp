#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef struct abc{
    int a,b;
    abc(){

    }
    abc(int _a,int _b){
        a = _a, b = _b;
    }
} abc;


int main(){

    int m,n;
    
    int a,b,c;
    cin >> m >> n;
    vector<abc> v(n, abc());
    int K = 0;
    vector<vector<int>> group(n+1);
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        K = max(K, c);
        v[i] = abc(a,b);
        group[c].push_back(i);
    }

    vector<int> f(m+1, 0);
    for(int k=1;k<=K;k++){ // K组
        for(int j=m;j>=0;j--){ // 价值
            for(int i=0;i<group[k].size();i++){ // 组内最大值
                if(j >= v[group[k][i]].a)
                    f[j] = max(f[j], f[j-v[group[k][i]].a]+v[group[k][i]].b);
            }
        }
    }

    cout << f[m] << std::endl;

    return 0;
}