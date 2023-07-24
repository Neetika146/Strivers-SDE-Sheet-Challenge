#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &nums, int n, int k) {
        priority_queue<int, vector<int>> p;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++) {
          p.push(nums[i]);
          q.push(nums[i]);
        }
        int maxi = 0, mini = 0;
        int i = k;
        while(--i){
            p.pop();
        }        
        maxi = p.top();

        int j = k;
        while(--j){
            q.pop();
        }
        mini = q.top();
        return {mini, maxi};
}