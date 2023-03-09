#include <iostream>
#include <string>
using namespace std;

bool isVal(int a){
    return (a >= 0 && a <= 255) ? true : false;
}
bool mtch(int a, int b){
    return (a & b) == a ? true : false; 
}
int main() {

    int a=0,b=0,c=0,d=0,e=0,er=0,pr=0;
    string str;
    while(cin >> str){ 
        int ip1=0,ip2=0,ip3=0,ip4=0;
        int mask = 0, cnt = 0;
        int mk1=0,mk2=0,mk3=0,mk4=0;
        int num_t = 0;
        for(int i=0;i<str.size();i++){
            char ch = str[i];
            if(ch=='~') {
                ip4 = num_t;
                mask=1;
                cnt = 0;
                num_t=0;
            } else if(ch=='.') {
                
                if(!mask){
                    if(!cnt){
                        ip1=num_t;
                    } else if(cnt==1){
                        ip2=num_t;
                    } else {
                        ip3 = num_t;
                    }
                } else {
                    if(!cnt){
                        mk1=num_t;
                    } else if(cnt==1){
                        mk2=num_t;
                    } else {
                        mk3 = num_t;
                    }
                }
                cnt++;
                num_t = 0;
            } else {
                num_t = num_t * 10 + ch - '0';
            }
        }
        mk4 = num_t;

        if(!(isVal(ip1)&&isVal(ip2)&&isVal(ip3)&&isVal(ip4)&&isVal(mk1)&&isVal(mk2)&&isVal(mk3)&&isVal(mk4))){
            er ++;
            continue;
        }
        if(!(mtch(ip1, mk1)&&mtch(ip2, mk2)&&mtch(ip3, mk3)&&mtch(ip4, mk4))){
            er ++;
            continue;
        }
        if(ip1==0 || ip1==127){
            continue;
        }
        if(ip1>=1&&ip1<=126){
            a++;
        }
        if(ip1>=128&&ip1<=191){
            b++;
        }
        if(ip1>=192&&ip1<=223){
            c++;
        }
        if(ip1>=224&&ip1<=239){
            d++;
        }
        if(ip1>=240&&ip1<=255){
            e++;
        }
        if(ip1==10){
            pr++;
        }
        if(ip1==172 && ip2>=16 && ip2 <=31){
            pr++;
        }
        if(ip1==192&&ip2==168){
            pr++;
        }

    }
    cout << a << " ";
    cout << b << " ";
    cout << c << " ";
    cout << d << " ";
    cout << e << " ";
    cout << er << " ";
    cout << pr << " ";
    return 0;
}
// 64 位输出请用 printf("%lld")