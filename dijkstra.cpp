#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int V, int edges, int S) {
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(V, INT_MAX);
        vector<pair<int, int>> adj[V];
        for(int i = 0; i < edges; i++){
          adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
          adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
        }

        // vector<int> parent(V);
        // for(int i = 0; i < V; i++){
        //     parent[i] = i;
        // }
        // vector<int> ans;
        
        distance[S] = 0;
        pq.push({S, 0});
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.first;
            int dis = it.second;
            pq.pop();
            
            for(auto i : adj[node]){
                int adjNode = i.first;
                int edW = i.second;
                if(dis + edW < distance[adjNode]){
                    distance[adjNode] = dis + edW;
                    pq.push({adjNode, distance[adjNode]});
                    // parent[adjNode] = node;
                }
            }
        }
        // if(distance[V-1] == 1e9) return {-1};
        return distance;
        // int node = V - 1;
        // while(parent[node] != node){
        //     ans.push_back(node);
        //     node = parent[node];
        // }
        // ans.push_back(S);
        // reverse(ans.begin(), ans.end());
        // return ans;
    // Write your code here.
}
