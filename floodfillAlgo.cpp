void helper(vector<vector<int>>& matrix, int sr, int m, int sc, int n, int color, int oldColor) {
        if(sr < 0 || sr > m-1 || sc < 0 || sc > n-1) return;
        if(matrix[sr][sc] == color) return;   
        if(matrix[sr][sc] != oldColor) return;      
        if(matrix[sr][sc] == oldColor) matrix[sr][sc] = color;
        helper(matrix, sr-1, m, sc, n, color, oldColor);
        helper(matrix, sr, m, sc-1, n, color, oldColor);
        helper(matrix, sr, m, sc+1, n, color, oldColor);
        helper(matrix, sr+1, m, sc, n, color, oldColor);        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> matrix = image;
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];
        helper(matrix, sr, m, sc, n, color, oldColor);
        return matrix;

    }