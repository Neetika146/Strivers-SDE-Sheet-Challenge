#include <bits/stdc++.h>
void func(int i, vector<vector<int>> &ans, vector<int> &ds, vector<int>& nums, int target){
        if(i == nums.size()){
            if(accumulate(ds.begin(), ds.end(), 0) == target){
                // ds.push_back(nums[i]);
                ans.push_back(ds);
                // for(int j = 0; j < ds.size(); j++){
                //     ds.pop_back();
                // }
            }
            return;
        }
        
        func(i+1, ans, ds, nums, target);
        // if(target >= nums[i]) {
            ds.push_back(nums[i]);
            func(i+1, ans, ds, nums, target); 
            ds.pop_back();
        // }        
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, ans, ds, arr, k);
        return ans;
    // Write your code here.
}