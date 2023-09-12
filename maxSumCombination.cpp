visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i, j});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x+1<m && !visited[x+1][y] && board[x+1][y] == 'X'){
                visited[x+1][y] = 1;
                q.push({x+1, y});
            }

            if(y+1<n && !visited[x][y+1] && board[x][y+1] == 'X'){
                visited[x][y+1] = 1;
                q.push({x, y+1});
            }

        }