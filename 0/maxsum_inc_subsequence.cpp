#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
		int omax = INT_MIN;
	    int dp[n];
	    for(int i = 0 ; i < n; i++){
	        int maxi = 0;
	        for(int j = 0; j < i; j++){
	            if(arr[i] > arr[j]){
	                if(maxi == 0){
	                    maxi = dp[j];
	                }
	                else if(dp[j] > maxi){
	                    maxi = dp[j];
	                }
	            }
	        }
	        
	        if(maxi == 0) dp[i] = arr[i];
	        else dp[i] = arr[i] + maxi;
	        
	        if(dp[i] > omax){
	            omax = dp[i];
	        }
	    }
	    return omax;
	// Write your code here
}