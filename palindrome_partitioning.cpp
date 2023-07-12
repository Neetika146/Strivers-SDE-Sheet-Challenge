#include <bits/stdc++.h> 
bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
}
void func(int ind, string s, vector<vector<string>> &ans, vector<string> &ds){
        if(ind == s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i < s.size(); i++){
            if(isPalindrome(s, ind, i)){
                ds.push_back(s.substr(ind, i - ind + 1));
                func(i+1, s, ans, ds);
                ds.pop_back();
            }
        }
}
vector<vector<string>> partition(string &s) 
{
        vector<vector<string>> ans;
        vector<string> ds;
        func(0, s, ans, ds);
        return ans;
    // Write your code here.
}