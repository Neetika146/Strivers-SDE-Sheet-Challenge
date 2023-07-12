#include<bits/stdc++.h>
void func(int i, vector<vector<int>> &ans, vector<int> &ds, vector<int>& nums, int target){
        if(target == 0){
            ans.push_back(ds);            
            return;
        }
        for(int ind = i; ind < nums.size(); ind++){
            if(ind>i && nums[ind] == nums[ind-1]) continue;
            if(nums[ind] > target) break;
            ds.push_back(nums[ind]);
            func(ind+1, ans, ds, nums, target - nums[ind]); 
            ds.pop_back();       
        }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int n, int target){
	vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        func(0, ans, ds, candidates, target);
        return ans;
	// Write your code here.
}
