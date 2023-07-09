#include <bits/stdc++.h> 
static bool cmp(vector<int> a, vector<int> b){
        return a[1] > b[1];
}
int jobScheduling(vector<vector<int>> &arr)
{
        sort (arr.begin(), arr.end(), cmp);
        int n = arr.size();
        
        vector<int> ans(10000, -1);
        
        int profit = 0;
        for (int i = 0; i < n; i++){
            for (int j = arr[i][0] - 1; j >= 0; j --){
                if (ans[j] == -1){
                    ans[j] = 1;
                    profit = profit + arr[i][1];
                    break;
                }
            }
        }
        return profit;
        // vector <int> res;
        // int count = 0;
        // for (int i = 0; i < n; i++){
        //     if(ans[i] != -1){
        //         count++;
        //     }
        // }
        // res.push_back(count);
        // res.push_back(profit);
        // return res;
}
