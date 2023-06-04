#include <bits/stdc++.h> 
long long maxSubarraySum(int nums[], int n)
{
        long long maxSub = nums[0];
        long long currSum = 0;
        for (int i = 0; i < n; i++){
            if (currSum < 0){
                currSum = 0;
            }
            currSum += nums[i];
            maxSub = max(maxSub, currSum);
        }
        if (maxSub < 0){
            return 0;
        }
        return maxSub;
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
}