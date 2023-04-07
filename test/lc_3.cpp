#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

// 12345
string int_to_string(int a){
    string s;
    while(a > 0){
        // num = ch -'0'
        int t = a % 10;
        s += (t+'0');
        a /= 10;
    }
    reverse(s.begin(),s.end());
    return s;
}
int string_to_int(string str){
    int num = 0;
    for(int i=0;i<str.size();i++){
        num = (num<<1)+(num<<3)+(str[i]-'0');
    }
    return num;
}
int find_bracket(string str){
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            return i;
        }
    }
    return 0;
}
vector<string> getFolderNames(vector<string>& names) {
        std::map<string, int> m;
        vector<string> v;
        int tip = 0;
        for(int i=0;i<names.size();i++){
            
            if(tip = find_bracket(names[i])){
                // gta(1)
                // 012345
                string base_name = names[i].substr(0,tip);
                string name_tag = names[i].substr(tip+1,names[i].size()-tip-2);
                int cur_cnt = string_to_int(name_tag);
                int map_cnt = m[base_name]+1;
                if(cur_cnt < map_cnt) {
                    v.push_back(base_name+"("+int_to_string(map_cnt)+")");
                } else {
                    v.push_back(names[i]);
                }
                m[base_name] ++;
            } else {
                 if(m.find(names[i])==m.end()){
                m[names[i]] = 0;
                v.push_back(names[i]);
            } else {
                int t = ++ m[names[i]];
                string stri = names[i]+"("+int_to_string(t)+")";
                v.push_back(stri);
            }
            }
           
        }
    return v;
}


int main(){
    //                         0       1        2       
    vector<string> names = {"kaido","kaido(1)","kaido","kaido(1)"};
    auto vi = getFolderNames(names);
    for(int i=0;i<vi.size();i++){
        cout << vi[i] <<std::endl;
    }
    return 0;
}