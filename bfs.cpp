#include <bits/stdc++.h> 
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
        vector<int> adj[V];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        for(int i = 0; i < V; i++){
            sort(adj[i].begin(), adj[i].end());
        }
        
        int vis[V] = {0};
        vector<int> bfs;
        for(int it = 0; it < V; it++){
            queue<int> q;
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    for(auto i : adj[node]){
                      if (!vis[i]) {
                        vis[i] = 1;
                        q.push(i);
                      }
                    }
                }
            }
        }

        return bfs;
    // Write your code here
}