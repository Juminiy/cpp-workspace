#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;
    cin >> s;
    int x=0,y=0;
    int n = s.size();
    bool val = true;
    int tn = 0;
    int cur = 0, pre = 0;
    int lr = 0, ud = 0;
    while ( cur < n ){
        char ch = s[cur];
        // [A|S|D|W][0-9]^2; 
        switch (ch) {
            // A9;
            // A10;
            // AD1
            // WS1
            // AW1
            // 1A1
            // 
            case ';':{
                if(cur-pre>3||cur-pre<2) val = false;
                if(lr!=0 && ud!=0) val = false;
                if(!(s[pre]=='A'||s[pre]=='W'||s[pre]=='S'||s[pre]=='D')) val = false;

                if(val){
                if(lr == -1) {
                    x -= tn;
                } else if(lr == 1){
                    x += tn;
                }
                if(ud == -1) {
                    y += tn;
                } else if (ud == 1){
                    y -= tn;
                }
                }
                tn = 0;
                val = true;
                pre = cur+1;  
                lr = ud = 0;
                // std::cout << x << "," << y << std::endl;
                break;
            }
            case 'A':{
                lr --;
                break;
            }
            case 'S':{
                ud ++;
                break;
            }
            case 'W':{
                ud --;
                break;
            }
            case 'D':{
                lr ++;
                break;
            }
            case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':        {
                tn = tn*10 + ch - '0';
                break;
            } default:{

            }
        }
        cur ++;
    }

    std::cout << x << "," << y << std::endl;

    return 0;
}
// 64 位输出请用 printf("%lld")