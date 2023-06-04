class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector <int> row;
        // vector <int> column;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    // matrix[0][j] = 0;
                    // matrix[i][0] = 0;
                    // row.push_back(i);
                    // column. push_back(j);
                    for (int k = 0; k < m; k++){
                        if (matrix[k][j] != 0){
                            matrix[k][j] = -99999;
                        }
                    }
                    for (int k = 0; k < n; k++){
                        if (matrix[i][k] != 0){
                            matrix[i][k] = -99999;
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < m; i++){
        //     if (matrix[i][0] == 0){
        //         for (int j = 0; j < n; j++){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
        // for (int j = 0; j < n; j++){
        //     if (matrix[0][j] == 0){
        //         for (int i = 0; i < m; i++){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == -99999){
                    matrix[i][j] = 0;
                }
            }
        }
        // for (int i = 0; i < column.size(); i++){
        //     for (int j = 0; j < m; j++){
        //         matrix[j][column[i]] = 0;
        //     }
        // }
        // int j = 0;
        // for (int i = 0; i < m; i++){
        //     if (i==row[j]){
        //         j++;
        //         for (int k = 0; k < n; k++){
        //             matrix[i][k]=0;
        //         }
        //     }
        // }
        // int l = 0;
        // for (int i = 0; i < n; i++){
        //     if (i==row[l]){
        //         l++;
        //         for (int k = 0; k < m; k++){
        //             matrix[k][i]=0;
        //         }
        //     }
        // }
    }
};