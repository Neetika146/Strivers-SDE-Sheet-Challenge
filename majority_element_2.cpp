#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &nums)
{
        map<int, int> m;
        vector<int> ans;
        for(int i = 0;i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto i: m){
            if(i.second > nums.size()/3){
                ans.push_back(i.first);
            }
        }
        return ans;

}