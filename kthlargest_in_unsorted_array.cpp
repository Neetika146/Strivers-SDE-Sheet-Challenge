#include <bits/stdc++.h> 
int kthLargest(vector<int>& nums, int size, int k) {
        priority_queue<int, vector<int>> pq;
        for(int i = 0; i < size; i++) pq.push(nums[i]);
        while(--k){
            pq.pop();
        }
        return pq.top();
    }