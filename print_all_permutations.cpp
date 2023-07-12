#include <bits/stdc++.h> 
void func(int ind, string& nums, vector<string> &ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i < nums.size(); i++){
            swap(nums[ind], nums[i]);
            func(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
}
vector<string> findPermutations(string &nums) {
        vector<string> ans;
        func(0, nums, ans);
        return ans;
    // Write your code here.
}