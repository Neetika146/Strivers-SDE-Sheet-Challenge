#include <bits/stdc++.h> 
int bellmonFord(int V, int m, int S, int dest, vector<vector<int>> &edges) {
        vector<int> distance(V+1, 1e9);
        distance[S] = 0;
        
        for(int i = 1; i <= V-1; i++){
            bool noupdate = true;
            for(auto i : edges){
                int u = i[0];
                int v = i[1];
                int dist = i[2];
                
                if(distance[u] != 1e9 && distance[u] + dist < distance[v]){
                    distance[v] = distance[u] + dist;
                    noupdate = false;
                }
            }
            if(noupdate) return distance[dest];
        }
        
        bool noupdate = true;
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int dist = i[2];
                
            if(distance[u] != 1e9 && distance[u] + dist < distance[v]){
                noupdate = false;
            }
        }
        if(!noupdate) return INT_MIN;
        return distance[dest];
}