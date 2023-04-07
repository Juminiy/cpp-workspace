#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> findSubstring(string s, vector<string>& words) {

    // arrangment of words
    


    // kmp 
    return vector<int>{};
}

int myAtoi(string s) {
        bool sgn = true;
        unsigned long long num = 0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch >= '0' && ch <='9'){ 
                num = (num << 1) + (num << 3) + ch - '0';
            } else if ( ch == '-'){
                sgn = false;
            }
        }
        int res = 1;
        if(sgn){
            if(num > 1<<31-1){
                res = 1<<31-1;
            }
            res = num;
        } else {
            // 
            // 0100 0000 0000 0000 0000 0000 0000 0000 
            if(num > 1<<31){
                res = num*-1;
            }
        }
        return res ;
}

int main(){

    cout << myAtoi( "   -42");


    return 0;
}