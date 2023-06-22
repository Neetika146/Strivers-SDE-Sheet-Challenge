#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    Kthlargest(int k, vector<int> &nums) {
        K = k;
        for (int i = 0; i < nums.size(); i++) {
          pq.push(nums[i]);
          if(pq.size() > K) pq.pop();
        }
       // Write your code here.
    }

    void add(int num) {
        // Write your code here.
        pq.push(num);
        if(pq.size() > K) pq.pop();
    }

    int getKthLargest() {            
        // while(--K && pq.size() > 0){
        //     pq.pop();
        // }
        return pq.top();
       // Write your code here.
    }

};