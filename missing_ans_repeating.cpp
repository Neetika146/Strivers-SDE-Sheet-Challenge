#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long sum1 = 0;
	long long sum2 = 0;
	for(int i = 0; i < n; i++){
		sum1 += arr[i];
		sum2 += (long long)arr[i] * (long long)arr[i];
	}
	sum1 -= (long long)n*(n+1)/2;
	sum2 -= (long long)n*(n+1)*(2*n+1)/6;
	sum2 /= sum1;
	long long x = (sum1+sum2)/2;
	return {(int)(x-sum1), (int)x};
	// Write your code here 
	
}
