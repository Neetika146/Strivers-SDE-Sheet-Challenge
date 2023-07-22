string longestPalinSubstring(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        string ans;
        for(int g = 0; g < n; g++){
            for(int i = 0, j = g;  j < n; i++, j++){
                if(g == 0){
                    dp[i][j] = 1;
                }
                else if(g == 1){
                    if(s[i] == s[j]) dp[i][j] = 1;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] == 1) dp[i][j] = 1;
                }
                if(dp[i][j]){
                    if(j - i + 1 > ans.length()){
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
            
        }
        return ans;
}