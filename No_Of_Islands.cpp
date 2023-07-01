#include<bits/stdc++.h>
void bfs(int i, int j, int m, int n, int** grid, vector<vector<int>> &visited){
        queue <pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        
        int directions[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto ways: directions){
                int nextx = x + ways[0];
                int nexty = y + ways[1];

                if(nextx >= 0 && nexty >= 0 && nextx < m && nexty < n && grid[nextx][nexty] == 1 && !visited[nextx][nexty]){
                    q.push({nextx, nexty});
                    visited[nextx][nexty] = 1;
                }
            }
        }

    }
int getTotalIslands(int** grid, int n, int m)
{
   vector<vector<int>> visited(m, vector<int> (n, 0));

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    bfs(i, j, n, m, grid, visited);
                    cnt++;
                }
            }
        }
        return cnt;
   // Write your code here.
}
