#include<bits/stdc++.h>
bool check(int start, vector<int> adj[], vector<int> &color){
        queue<int>q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i: adj[node]){
                if(color[i] == -1){
                    q.push(i);
                    color[i] = !color[node];
                }
                else if(color[i] == color[node]) return false;
            }
        }
        return true;
    }

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
				if(edges[i][j] == 1){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
        }
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1 && check(i, adj, color) == false) return false;
        }
        return true;
	// Write your code here.
}