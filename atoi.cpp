#include <bits/stdc++.h> 
int atoi(string s) {
        double ans = 0;
        const int n = s.length();
        if(n == 0) return 0;
        bool negative = false;
        bool positive = false;
        int i = 0;
        while(s[i] == ' ') i++;

        for(; i < n; i++){
            if(s[i] == '-') {
                negative  = true;
            }
            else if(s[i] == '+')  positive = true;
            else if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
                ans = ans*10 + (s[i] - '0');
            }
            else {
                continue;
            }
        }
        if(negative && positive) return 0;
        if(negative == true) ans = -ans;
        ans = ans > INT_MAX ? INT_MAX : ans;
        ans = ans <INT_MIN ? INT_MIN : ans;
        return (int)ans;
    // Write your code here.
}