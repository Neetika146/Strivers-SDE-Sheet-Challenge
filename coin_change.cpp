#include<bits/stdc++.h>
long f(int ind, int T, int *arr, vector<vector<long>> &dp){
        if(ind == 0) return T%arr[0] == 0;
        if(dp[ind][T] != -1) return dp[ind][T];
        long notTake = f(ind -1, T, arr, dp);
        long take = 0;
        if(arr[ind] <= T) take = f(ind, T - arr[ind], arr, dp);
        return dp[ind][T] = take + notTake;
    }
long countWaysToMakeChange(int *arr, int n, int value)
{
    vector<long> prev(value+1, 0), curr(value+1, 0);
    for(int i = 0; i <= value; i++) prev[i] = (value%arr[0] == 0);

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= value; T++){
            long notTake = prev[T];
            long take = 0;
            if(arr[ind] <= T) take = curr[T- arr[ind]];
            curr[T] = take + notTake;
        }
        prev = curr;
    }
    return prev[value];
    // vector<vector<long>> dp(n, vector<long>(value+1, 0));
    // for(int i = 0; i <= value; i++) dp[0][i] = (value%arr[0] == 0);

    // for(int ind = 1; ind < n; ind++){
    //     for(int T = 0; T <= value; T++){
    //         long notTake = dp[ind -1][T];
    //         long take = 0;
    //         if(arr[ind] <= T) take = dp[ind][T- arr[ind]];
    //         dp[ind][T] = take + notTake;
    //     }
        
    // }
    // return dp[n-1][value];
    //Write your code here
}