class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        vector<int> ans;
        priority_queue<pair<int,pair<int, int>>>pq;
        pq.push({A[N-1]+ B[N-1], {N-1, N-1}});
        set<pair<int,int>>s;
        s.insert({N-1, N-1});
        
        while(K--){
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            ans.push_back(sum);
            pq.pop();
            
            if(i >= 1 && s.find({i-1, j}) == s.end()) {
                pq.push({A[i-1] + B[j],{i-1,j}});
                s.insert({i-1, j});
            }
            if(j >= 1 && s.find({i, j-1}) == s.end()) {
                pq.push({A[i] + B[j-1], {i, j-1}});
                s.insert({i, j-1});
            }
        }
        return ans;
        // code here
    }
};