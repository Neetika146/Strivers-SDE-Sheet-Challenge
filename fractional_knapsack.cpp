#include <bits/stdc++.h> 
static bool cmp (pair<int, int> &a, pair<int, int> &b){
        return ((double) a.second / a.first) > ((double) b.second / b.first);
    }
    
double maximumValue (vector<pair<int, int>>& arr, int n, int W)
{
        sort(arr.begin(), arr.end(), cmp);
        
        double profit = 0;
        
        for (int i = 0; i < n; i++){
            if (arr[i].first <= W){
                profit = profit + arr[i].second;
                W = W - arr[i].first;
            }
            else{
                profit += (double)((double) arr[i].second * W / (double)arr[i].first);
                break;
            }
        }
        
        return profit;
    // Write your code here.
    // ITEMS contains {first, second} pairs.
}