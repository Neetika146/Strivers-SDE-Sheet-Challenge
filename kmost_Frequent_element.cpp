vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
        unordered_map <int, int> mp;
        // int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto i : mp){
            pq.push({i.second, i.first});
        }

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    // Write your code here.
}