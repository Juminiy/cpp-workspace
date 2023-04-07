#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){

    int n,k;
    cin >> n >> k;
    vector<int> si(n, 0);
    for(int i=0;i<n;i++)
        cin >>si[i];
    // 1 2 3 4 5 6 -> 6 
    // 1 1 1 1 1 1 -> 2 
    // n = 6, k = 4
    int l = 0, r = n-1, ans = 0xfffff;
    while(l < r && k > 0){
        if(si[l]+si[r-1] < si[r]){
            ans = min(ans, si[l]+si[r-1]);
            ans = min(ans, si[r]);
            r -= 2, l ++;
            k -= 2;
        } else {
            ans = min(ans, si[r]);
            r --;
            k -= 1;
        }

    }

    cout << ans << std::endl;

    return 0;
}