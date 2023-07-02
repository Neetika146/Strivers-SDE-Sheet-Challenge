#include<bits/stdc++.h>
void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &s){
    visited[node] = 1;

    for(int i: adj[node]){
        if(!visited[i]) dfs(i, adj, visited, s);
    }
    s.push(node);
}

void revdfs(int node, vector<int> transpose[], vector<int> &visited, vector<int> &temp){
    visited[node] = 1;
    temp.push_back(node);

    for(int i: transpose[node]){
        if(!visited[i]) revdfs(i, transpose, visited, temp);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<int> adj[n];
    for(int i = 0; i < edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    stack<int> s;
    vector<int> visited(n, 0);

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, adj, visited, s);
        }
    }
    vector<int> transpose[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    for (int i = 0; i < edges.size(); i++) {
        transpose[edges[i][1]].push_back(edges[i][0]);

    }

    while(!s.empty()){
        int node = s.top();
        s.pop();

        if(!visited[node]){
            vector<int> temp;
            revdfs(node, transpose, visited, temp);
            ans.push_back(temp);
        }
    }
    return ans;
    // Write your code here.
}