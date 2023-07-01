#include <bits/stdc++.h> 
int topoSort(int V, vector<int> adj[]) 
	{
	    int cnt = 0;
	    vector<int> indegree(V+1);
	    for(int i = 1; i <= V; i++){
    	    for(auto it : adj[i]){
    	        indegree[it]++;
    	    }
	    }
	    
	    queue<int> q;
	    for(int i = 1; i <= V; i++){
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        cnt++;
	        q.pop();
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
      if(cnt == V) return 0;
	    return 1;
	    // code here
	}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> adj[n+1];
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i].first].push_back(edges[i].second);
    }
    return topoSort(n, adj);
}