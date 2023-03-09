#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) { 
    for(int i=0;i<items2.size();i++){
        bool fnd = 0;
        for(int j=0;j<items1.size();j++){
            if(items1[j][0]==items2[i][0]){
                items1[j][1] += items2[i][1];
                fnd = true;
                break;
            }
        }
        if(!fnd){
            items1.push_back(items2[i]);
        }
    }
    sort(items1.begin(), items1.end(), [](vector<int>a , vector<int>b) -> bool {
        return a[0] < b[0];
    });
    return items1;
}

vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]] = i;
        }
        int t=0;
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){ 
                if(m.find(-nums[i]-nums[j])!=m.end() && (t = m[-nums[i]-nums[j]])!= i && t!=j){
                    v.push_back({i,j,t});
                }
            }
        }
        return v;
}

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}ListNode;

class ListCmp{
    public:
    ListNode *list;
    ListCmp(ListNode *l){
        this->list = l;
    }
    bool operator < (ListCmp cmpd) const{
        return this->list->val > cmpd.list->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) { 
    priority_queue<ListCmp> q;
    for(int i=0;i<lists.size();i++){
        if(lists[i])
            q.push(ListCmp(lists[i]));
    }
    ListNode *pre=nullptr, *head=nullptr;
    while(!q.empty()){
        ListCmp lc = q.top(); q.pop();
        if(!head){
            head = lc.list;
            pre = head;
        } else {
            pre->next = lc.list;
            pre = pre->next;
        }
        if(lc.list->next){
            q.push(ListCmp(lc.list->next));
        }
    }
    return head;
}
void printListNode(ListNode *list){
    while(list){
        cout << list->val << "->";
        list = list->next;
    }
    cout << "null" << std::endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
    int i = 0, j = 0, l = 0, pre = 0, cur = 0;
    int m = nums1.size(), n = nums2.size();
    int k = (m+n) >> 1, tag = 1, pretag = 1;
    while(i < m && j < n) {
        if(l-1==k){
            double t = 0;
            t = (tag == 1) ? nums1[cur] : nums2[cur];
            if((m+n)%2==0){
                t += (pretag == 1) ? nums1[pre] : nums2[pre];
                t /= 2;   
            }
            return t;
        }
        pretag = tag, pre = cur;
        if(nums1[i]<nums2[j])
            tag = 1, cur = i, i++;
        else 
            tag = 2, cur = j, j++;
        l++;
    }
    while(i < m){
        if(l-1==k){
            double t = 0;
            t = nums1[cur];
            if((m+n)%2==0){
                t += nums1[pre];
                t /= 2;   
            }
            return t;
        }
        pre = cur;
        cur = i;
        i++;
        l++;
    }
    while(j < n){
        if(l-1==k){
            double t = 0;
            t = nums2[cur];
            if((m+n)%2==0){
                t += nums2[pre];
                t /= 2;   
            }
            return t;
        }
        pre = cur;
        cur = j;
        j++;
        l++;
    }
    return 0;
}

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> v(n-2, vector<int>(n-2, 0));

        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int cmp = grid[i+1][j+1];
                for(int pi=i;pi<=i+2;pi++){
                    for(int pj=j;pj<=j+2;pj++){
                        cmp = cmp > grid[pi][pj] ? cmp : grid[pi][pj];
                    }
                }
                v[i][j] = cmp;
            }
        }

        return v;
}

int main(){
    std::vector<int> v1 = {1,2}, v2 = {3,4};
    cout << findMedianSortedArrays(v1,v2);
    return 0;
}