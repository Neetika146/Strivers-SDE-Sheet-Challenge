#include <bits/stdc++.h> 
void add(vector<vector<int>> &ans, vector<vector<int>> &vis, int n){
  vector<int> temp;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      temp.push_back(vis[i][j]);
    }
  }
  temp.pop_back();
  temp.push_back(1);
  ans.push_back(temp);
}
void solve(int i, int j, vector<vector<int>> &m, int n, vector<vector<int>> &ans, vector<vector<int>> &vis){
        if(i == n-1 && j == n-1){
            add(ans, vis, n);
            return;
        }
        if(i+1 < n && !vis[i+1][j] && m[i+1][j] == 1){
            vis[i][j] = 1;
            solve(i+1, j, m, n, ans, vis);
            vis[i][j] = 0;
        }
        if(j-1 >= 0 && !vis[i][j-1] && m[i][j-1] == 1){
            vis[i][j] = 1;
            solve(i, j-1, m, n, ans, vis);
            vis[i][j] = 0;
        }
        if(j+1 < n && !vis[i][j+1] && m[i][j+1] == 1){
            vis[i][j] = 1;
            solve(i, j+1, m, n, ans, vis);
            vis[i][j] = 0;
        }
        if(i-1 >= 0 && !vis[i-1][j] && m[i-1][j] == 1){
            vis[i][j] = 1;
            solve(i-1, j, m, n, ans, vis);
            vis[i][j] = 0;
        }
        
}
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        // Your code goes here
    }
vector<vector<int> > ratInAMaze(vector<vector<int> > &m, int n){
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        if(m[0][0] == 1) solve(0, 0, m, n, ans, vis);
        return ans;
  // Write your code here.
}