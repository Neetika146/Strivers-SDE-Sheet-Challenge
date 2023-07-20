#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &nums, int k) 
{
    vector<int> ans;
    map<int, int> mp;
    for(int i = 0; i < k; i++){
        mp[nums[i]]++;
    }    
    ans.push_back(mp.size());
    for(int i = k; i < nums.size(); i++){        
        mp[nums[i-k]]--;
        if(mp[nums[i-k]] == 0) mp.erase(nums[i-k]);
        mp[nums[i]]++;
        ans.push_back(mp.size());
    }
    return ans;
    // Write your code here
	
}
