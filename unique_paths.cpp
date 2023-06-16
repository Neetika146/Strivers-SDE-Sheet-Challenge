#include <bits/stdc++.h> 
int dp[101][101];
int uniquePaths(int m, int n) {
	int dp[m+1][n+1];
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= n; j++){
                dp[i][j] = 1;
            }
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
}