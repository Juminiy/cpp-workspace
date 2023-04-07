#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

/*
0 0 1 2 3
0 0,0 0,1 0,2 0,3
1 1,0 1,1 1,2 1,3
2 2,0 2,1 2,2 2,3
3 3,0 3,1 3,2 3,3
*/
// . Q . .
// . . . Q
// Q . . .
// . . Q . 
class Solution {
private:
    vector<vector<string>> v; 
    vector<int> tag;
    int nqs;
public:
    void print2DimVector() const{
        assert(v.size());
        for(int i = 0; i < v.size(); i ++){
            assert(v[i].size());
            for(int j = 0; j < v[i].size(); j ++){
                std::cout << v[i][j] << std::endl;
            }
            std::cout << "------------" <<std::endl;
        }
    }
    bool checknq(int pi, int pj) const{
    
    // row check
    for(int i=0;i<pi;i++){
        if(tag[i] == pj){
            return false;
        }
    } //check pass 

    //// bound check check pass 
    // pi+pj check 
    int piaj = pi-pj, ti = pi-1, tj = ti - piaj;
    while(ti>=0&&ti<pi&&tj>=0&&tj<nqs){
        if(tag[ti] == tj)
            return false;
        ti --, tj --;
    }
    // pi-pj check
    int pimj = pi + pj;
    ti = pi-1, tj = pimj - ti;
    while(ti>=0&&ti<pi&&tj>=0&&tj<nqs){
        if(tag[ti] == tj)
            return false;
        ti --, tj ++;
    }

    return true;
}
    // Q . . .
// . . . Q
// . Q . .
// . . Q . 
void dfsnq(int cur){
    if(cur == nqs){
        vector<string> vi(nqs, string(nqs, '.'));
        for(int i=0;i<nqs;i++)
            vi[i][tag[i]] = 'Q';
        v.push_back(vi);
        return ;
    }

    for(int i=0;i<nqs;i++){
        if(checknq(cur, i)){
            tag[cur] = i; 
            dfsnq(cur+1);
            tag[cur] = 0xffffff;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    nqs = n;
    tag.assign(n, 0xffffff);
    dfsnq(0);
    return v;
}

};


int main(){

    Solution *s = new Solution();
    s->solveNQueens(4);
    s->print2DimVector();

    return 0;
}