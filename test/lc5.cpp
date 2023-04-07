#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            switch (ch) {
                case '(': case '{': case '[': {
                    stk.push(ch);
                    break;
                }
                case ')' :{
                    if(!stk.empty() && stk.top()=='('){
                        stk.pop();
                    } else {
                        return false;
                    }
                    break; 
                }
                case '}' :{
                    if(!stk.empty() && stk.top()=='{'){
                        stk.pop();
                    } else {
                        return false;
                    }
                    break; 
                }
                case ']' :{
                    if(!stk.empty() && stk.top()=='['){
                        stk.pop();
                    } else {
                        return false;
                    }
                    break; 
                }
                default :{}
            }
        }
        return stk.empty();
}

// 1->2->3->4->5
//
ListNode* reverseList(ListNode* head) {
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode *headNext = nullptr, *resHead = nullptr;
    while(head) {
        resHead = head->next;
        head->next = headNext;
        headNext = head;
        head = resHead;
    }
    return headNext;
}
class KthLargest {
    private: int kth;
    private: priority_queue<int, vector<int>, std::greater<int>> lq;
    private: priority_queue<int, vector<int>, std::less<int>> gq;

public:

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i=0;i<nums.size();i++){
            if(lq.size() < k) {
                lq.push(nums[i]);
            } else {
                gq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(lq.size()<kth){ 
            lq.push(val);
        } else {
            if(val > lq.top()){
                gq.push(lq.top());
                lq.pop();
                lq.push(val);
            } else {
                gq.push(val);
            }
        }
        return lq.top();
    }
};

int main(){

    
    vector<int> nums{0};
    KthLargest kths(2, nums);
    cout << kths.add(-1) << std::endl;
    cout << kths.add(1) << std::endl;
    cout << kths.add(-2) << std::endl;
    cout << kths.add(-4) << std::endl;
    cout << kths.add(3) << std::endl;
    return 0;
}