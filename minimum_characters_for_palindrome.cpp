#include<bits/stdc++.h>
int minCharsforPalindrome(string str) {
	int n = str.size();
	int i = 0, j = n-1, k = j;

	while(j >= i){
		if(str[i] != str[j]){
			i = 0;
			k--;
			j = k;
		}
		else{
			i++;
			j--;
		}
	}	
	return n - k - 1;
}
// #include<bits/stdc++.h>
// int lcs(string s, string t)
// {
// 		int n = s.size();
//         int m = t.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1));
//         for(int i = 0; i <= n; i++) dp[i][0] = 0;
//         for(int j = 0; j <= m; j++) dp[0][j] = 0;
//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= m; j++){
//                 if(s[i-1] == t[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[n][m];
// 	//Write your code here
// }
// int minCharsforPalindrome(string str) {
// 	int n = str.length();
// 	string t = str;
// 	reverse(t.begin(), t.end());
// 	return n - lcs(str, t);
// 	// Write your code here.
	
// }
