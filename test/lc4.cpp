#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minimumDeletions(string s) {
    
    int n = s.size(), ans = 0xffffff;
    vector<int> va(n, 0), vb(n, 0);

    if(s[0]=='b') va[0] = 1;
    if(s[n-1]=='a') vb[0] = 1;

    for(int i=1;i<n;i++){
        va[i] = (s[i]=='b') ? va[i-1]+1 : va[i-1];
    }
    for(int i=n-2;i>=0;i--){
        vb[i] = (s[i]=='a') ? vb[i+1]+1 : vb[i+1];
    }
    for(int i=0;i<n;i++){
        ans = std::min(ans, va[i]+vb[i]-1);
    }

    return ans;

}


int main(){

    cout << minimumDeletions("bbaaaaabb") << std::endl; 

    return 0;
}