int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
        // int n = matrix.size();
	    
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++){
            matrix[i][i] = 0;
        }

        for(auto i : edges){
            int u = i[0] - 1, v= i[1] - 1, wt = i[2];
            matrix[u][v] = wt;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                  if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9) {
                    matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
                  }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(matrix[i][i] < 0){
                return INT_MIN;
            }
        }
        
        return matrix[src-1][dest-1];
    // Write your code here.
}