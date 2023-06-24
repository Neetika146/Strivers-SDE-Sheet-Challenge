    vector<vector<int>> ans;
    void dfs(int node, vector<int> adj[], vector<int> &temp, int vis[]){
        vis[node] = 1;
        temp.push_back(node);
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i, adj, temp, vis);
            }
        }
    }

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
        int vis[V] = {0};
        vector<int> adj[V];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<int>> ans;
        for(int i = 0 ; i < V; i++){
            if(!vis[i]){
                vector<int> temp;
                dfs(i, adj, temp, vis);
                ans.push_back(temp);
            }
        }
        
        return ans;
    // Write your code here
}