#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &nums, int target){
        vector<vector<int>> ans;
        // unordered_map <int, int> m;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] == target){
                  ans.push_back({nums[i], nums[j]});
                }
            }
        }
        // for (int i = 0; i <= nums.size()/2; i++){
        //     if (m.find(target - nums[i]) != m.end()) {
        //         ans.push_back({nums[i], target - nums[i]});
        //     }
        // }
        // reverse(ans.begin(), ans.end());
        return ans;
        // vector <vector<int>> temp;
        // unordered_map <int, int> m;
        // for (int i = 0; i < nums.size(); i++){
        //    vector <int> ans;
        //     if(m.find(target - nums[i]) != m.end()){
        //         ans.push_back(m[target - nums[i]]);
        //         ans.push_back(i);
        //     }
        //     if(ans.size()>0){
        //        temp.push_back(ans);
        //     }
        //     m[nums[i]] = i;
        // }
        // return temp;
}