#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
        vector<pair<pair<int, int>, int>> ans;
        vector<pair<int, int>> adj[n+1];
        vector<int> parent(n+1, -1);
        vector<int> distance(n+1, INT_MAX);
        for(int i = 0; i < m ; i++){
            int u = g[i].first.first;
            int v = g[i].first.second;
            int wt = g[i].second;
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        distance[1]=0;
        parent[1]=-1;
        pq.push({0, 1});
        vector<int> visited(n+1, 0);
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            if(visited[node] == 1) continue;
            visited[node] = 1;
            // sum += dist;
            
            for(auto i : adj[node]){
                int adjNode = i.first;
                int wt = i.second;
                if(visited[adjNode] == 0 && distance[adjNode]>wt) {
                    distance[adjNode] = wt;
                    parent[adjNode] = node;
                  pq.push({wt, adjNode});
                }
            }
        }
        for(int i = 2; i <= n; i++){
            ans.push_back({{parent[i], i}, distance[i]});
        }
        return ans;
    // Write your code here.
}
