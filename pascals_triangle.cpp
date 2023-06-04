#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int numRows) 
{
        vector<vector<long long int>> ans(numRows);
        for (int i = 0; i < numRows; i++){
            ans[i].resize(i+1,1);
            for (int j = 1; j < i; j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        // for (int i = 0; i < numRows; i++){
        //     vector <int> temp;
        //     for (int j = 0; j <= i; j++){
        //         if (j>1){
        //             break;
        //         }
        //         temp.push_back(1);
        //         for (int k = j; k < i-1; k++){
        //             temp.push_back(ans[i-1][k]+ans[i-1][k+1]);
        //         }
        //     }
        //     ans.push_back(temp);
        // }
        return ans;
}
