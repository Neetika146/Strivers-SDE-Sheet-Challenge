#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int m, int n)
{
        if(grid.empty()) return 0;
        queue<pair<pair<int, int>, int>>q;
        int visited[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else visited[i][j] = 0;
            }
        }
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int tm = 0;
        

        
        while(!q.empty()){            
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            tm = max(tm, time);
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = x + delrow[i];
                int ncol = y + delcol[i];

                if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, time+1});
                    visited[nrow][ncol] = 2;
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] != 2 && grid[i][j] == 1) return -1;
            }
        }
        return tm;
    // Write your code here. 
}