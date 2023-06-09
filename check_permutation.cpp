#include <bits/stdc++.h> 
bool areAnagram(string &s, string &t){
    if (s.length() != t.length()) return false;
        unordered_map <char, int> m;
        for (int i = 0; i < s.length(); i++){
            m[s[i]]++;
            m[t[i]]--;
        }
        for (auto i : m){
            if(i.second){
                return false;
            }
        }
        return true;
}