#include<bits/stdc++.h>
bool check(int start, int col,  vector<int> adj[], vector<int> &color){
    color[start] = col;

	for(auto i : adj[start]){
		if(color[i] == -1){
			if(!check(i, !col, adj, color)) return false;
		}
		else if(color[i] == col) return false;
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
            if(color[i] == -1){
				if(check(i, 0, adj, color) == false) return false;
			}
        }
        return true;
	// Write your code here.
}