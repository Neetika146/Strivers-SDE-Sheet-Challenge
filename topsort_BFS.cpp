#include <bits/stdc++.h> 
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> indegree(V);
	    for(int i = 0; i < V; i++){
    	    for(auto it : adj[i]){
    	        indegree[it]++;
    	    }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++){
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    return ans;
	    // code here
	}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    for(int i = 0; i < e; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    return topoSort(v, adj);
}