bool dfs(int src, vector<int> adj[], vector<int> &visited, vector<int> &dfsvis){
        visited[src] = 1;
        dfsvis[src] = 1;
        for(auto it : adj[src]){
            if(!visited[it]){
                if(dfs(it, adj, visited, dfsvis)) return true;
            }
            else if(dfsvis[it]) return true;
        }
        dfsvis[src] = 0;
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
    }
int detectCycleInDirectedGraph(int V, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> visited(V+1, 0);
  vector<int> dfsvis(V+1, 0);
  
  vector<int>adj[V+1];
  for(int i = 0; i < V; i++){
    adj[edges[i].first].push_back(edges[i].second);
  }


  for(int i = 1; i <= V; i++){
    if(!visited[i]){
        if(dfs(i, adj, visited, dfsvis)) return 1;
    }
  }
  return 0;
}