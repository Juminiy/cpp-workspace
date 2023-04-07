#include <iostream>
#include <queue>
using namespace std;

// < < 1
// < > 3 
// > < 1
// > > 2
// t 
class pm{
  
  public :
    int num,t,x;
    pm(){}
    pm(int _num, int _t, int _x){
      num = _num, t = _t, x = _x;
    }
    bool operator < (const pm &comped) const{
      if(x == comped.x){
        return t > comped.t;
      }
      return x > comped.x;
    }
};

int main(){
    
  int n,num,x;
  cin >> n;
  priority_queue<pm> q; 
  char ch;
  for(int i=0;i<n;i++){
    cin >> ch;
    if(ch == 'a'){
      cin >> num >> x;
      pm pma = pm(num, i, x);
      q.push(pma);
    } else {
      cout << q.top().num << std::endl;
      q.pop();
    }
  }
  
  return 0;
}