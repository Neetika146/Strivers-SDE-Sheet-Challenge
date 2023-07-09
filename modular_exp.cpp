#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
    int result = 1;
    while(n>0){
        if(n&1){
            result = ( 1LL * (result) * (x)%m)%m;
        }
        x = ( 1LL * (x)%m * (x)%m)%m;
        n = n >> 1;
    }

    return result;
	// int ans = 1;
    //     if (x == 1 || (x == -1 && n % 2 == 0)){
    //         return abs(x);
    //     }
    //     if (x == -1 && n % 2 != 0){
    //         return -1;
    //     }
    //     if (n == INT_MIN){
    //         return 0;
    //     }
    //     if (n < 0){
    //         x = 1/x;
    //         n = abs(n);
    //     }   
    //     while(n){
    //         if (n % 2){
    //             ans = ans * x;
    //             n--;
    //         }  
    //         else{
    //             x = x * x;
    //             n = n/2;
    //         }
    //     }   
    //     // for(int i = 0; i < n; i++){
    //     //     ans *= x;
    //     // }
    //     return ans;
}