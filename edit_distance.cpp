int editDistance(string s1, string s2)
{
        int n = s1.size();
        int m = s2.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // for(int i = 0; i <= n; i++) dp[i][0] = i;
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int j = 0; j <= m; j++) prev[j] = j;
        for(int i = 1; i <= n; i++){
            curr[0] = i;
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
                else curr[j] = 1 + min(curr[j-1], min(prev[j-1], prev[j]));
            }
            prev = curr;
        }
        return prev[m];
    //write you code here
}