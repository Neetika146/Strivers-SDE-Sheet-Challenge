#include <bits/stdc++.h>
#include <string>
string longestCommonPrefix(vector<string> &strs, int n)
{
        if(strs.size() == 0){
            return " ";
        }
        string ans;
        sort(strs.begin(), strs.end());
        // int n = strs.size();
        for (int i = 0; i < strs[0].size(); i++){
            if(strs[0][i] == strs[n-1][i]){
                ans.push_back(strs[0][i]);
            }
            else{
                break;
            }
        }
        return ans;
    // Write your code here
}


