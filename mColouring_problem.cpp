bool isPossible(int node, int colour[], vector<vector<int>> &graph, int col, int n){
        for(int i = 0; i < n; i++){
            if(i != node && graph[node][i] == 1 && colour[i] == col) return false;
        }
        return true;
}
bool func(int node, int colour[], vector<vector<int>> &graph, int m, int n){
        if(node == n) return true;
        for(int col = 1; col <= m; col++){
            if(isPossible(node, colour, graph, col, n)){
                colour[node] = col;
                if(func(node + 1, colour, graph, m, n)) return true;
                else colour[node] = 0;
            }
        }
        return false;
}
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        // your code here
    }
string graphColoring(vector<vector<int>> &graph, int m) {
    int n = graph.size();
    int colour[n] = {0};
    if(func(0, colour, graph, m , n)) return "YES";
    return "NO";
    // Write your code here
}