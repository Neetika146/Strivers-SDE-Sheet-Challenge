#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
    if(n>m) return ninjaAndLadoos(arr2, arr1, m, n, k);
        int low = max(0, k-m), high = min(k, n);
        while(low <= high){
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            
            int l1 = cut1==0 ? INT_MIN :arr1[cut1-1];
            int l2 = cut2==0 ? INT_MIN :arr2[cut2-1];
            int r1 = cut1==n ? INT_MAX :arr1[cut1];
            int r2 = cut2==m ? INT_MAX :arr2[cut2];
            
            if(l2 <= r1 && l1 <= r2) return max(l1, l2);
            else if(l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
        }
        return 1;
    // Write your code here.
}