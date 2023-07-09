#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > A) {
        // int i = 0, j = 0;
        // int currSum = A[0];
        // int len = 0;
        // int n = A.size();

        // while(j < n){
        //     while(currSum > 0 && i <= j){
        //         currSum -= A[i];
        //         i++;
        //     }
        //     if(currSum == 0) len = max(len, j - i + 1);            
        //     j++;            
        //     if(j < n) currSum += A[j];
        // }
        // return len;
    map <long long, int> mp;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0; i < A.size(); i++){
        sum += A[i];
        if(sum == 0) maxLen = max(maxLen, i+1);
        long long rem = sum ;
        if(mp.find(rem) != mp.end()) maxLen = max(maxLen, i - mp[rem]);
        if(mp.find(sum) == mp.end()) mp[sum] = i;
    }
    return maxLen;
    // int n = A.size();
    // int maxLen = 0;
    // for(int i = 0; i < n; i++){
    //     int sum = 0;
    //     for(int j = i; j < n; j++){
    //         sum += A[j];
    //         if(sum == 0) maxLen = max(maxLen , j - i + 1);
    //     }
    // }
    // return maxLen;
}