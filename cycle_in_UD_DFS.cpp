#include<bits/stdc++.h>
bool dfs(int src, int parent, vector<int> adj[], vector<int> &visited){
        visited[src] = 1;
        for(auto it : adj[src]){
            if(!visited[it]){
                if(dfs(it, src, adj, visited)) return true;
            }
            else if(parent != it) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V+1, 0);
        for(int i = 1; i <= V; i++){
          if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
              return true;
          }
        }
        return false;
    }
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(n, adj)){
        return "Yes";
    }
    return "No";
    // Write your code here.
}
