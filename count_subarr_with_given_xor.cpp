#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int count = 0;
    for (int i = 0; i < arr.size(); i++){
        xr = xr ^ arr[i];
        int k = xr ^ x;
        count += mpp[k];
        mpp[xr]++;
    }
    return count;
    //    Write your code here.
}