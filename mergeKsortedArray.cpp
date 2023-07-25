#include <bits/stdc++.h> 
// class triplet{
//     int data, i, j;
//     triplet(int data, int i, int j){
//         this->data = data;
//         this->i = i;
//         this->j = j;
//     }
// };
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> ans;
    for(int i = 0; i < kArrays.size(); i++){
      pq.push({kArrays[i][0], {i, 0}});
    }
    while(!pq.empty()){
        auto t = pq.top();
        int data = t.first;
        int i = t.second.first;
        int j = t.second.second;
        if(j+1 < kArrays[i].size()) pq.push({kArrays[i][j+1], {i, j + 1}});
        ans.push_back(data);
        pq.pop();
    }
    return ans;
    // Write your code here. 
}
