#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int len = 0, l = 0, r = 0;
    int n = s.size();
    vector<int> mp(256, -1);
    while(l < n  && r < n){
        if(mp[s[r]] != -1) l = max(l, mp[s[r]] + 1);            
        mp[s[r]] = r;            
        len = max(len , r-l+1);
        r++;
    }
    return len;
    //Write your code here
}