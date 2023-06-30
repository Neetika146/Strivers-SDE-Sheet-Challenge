#include<bits/stdc++.h>
bool detect(int src, vector<int> adj[], vector<int> &visited){
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto ele :adj[node]){
                if(!visited[ele]){
                    visited[ele] = 1;
                    q.push({ele, node});
                }
                else if(parent != ele){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V+1, 0);
        for(int i = 1; i <= V; i++){
            if(!visited[i]){
                if(detect(i, adj, visited)){
                    return true;
                }
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
