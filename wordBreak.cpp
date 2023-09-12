class Solution {
public:
    int helper(int i, string s, set<string>& wordDict, vector<int> &dp){
        if(i == s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j = i; j < s.size(); j++){
            temp += s[j];
            if(wordDict.find(temp) != wordDict.end()){
                if(helper(j+1, s, wordDict, dp)) return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        set<string> st;
        for(auto a: wordDict) st.insert(a);
        return helper(0, s, st, dp);
    }
};