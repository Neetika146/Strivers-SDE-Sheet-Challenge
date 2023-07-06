#include <bits/stdc++.h> 
int maximumProduct(vector<int> &nums, int n)
{
		int product = INT_MIN;
        int prefix = 1, suffix = 1;

        for(int i = 0; i < n; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            product = max(product, max(prefix, suffix));
        }
        return product;
	// Write your code here
}
