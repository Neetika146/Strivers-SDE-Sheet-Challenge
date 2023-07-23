#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
		string s = "1";
        for(int i = 2; i <= n; i++){
            string t = "";
            s = s + '&';
            int cnt = 1;
            for(int j = 1; j < s.length(); j++){
                if(s[j] == s[j-1]){
                    cnt++;
                }
                else{
                    t = t + to_string(cnt);
                    t = t + s[j-1];
                    cnt = 1;
                }
            }
            s = t;
        }
        return s;
}