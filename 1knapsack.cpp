#include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
	 vector<int> prev(W+1, 0);
        for(int i  = wt[0]; i <= W; i++) prev[i] = val[0];
        
        
        for(int ind = 1; ind < n; ind++){
            for(int j = W; j >= 0; j--){
                int not_take = prev[j];
                int take  = INT_MIN;
                if(wt[ind] <= j){
                    take  = val[ind] + prev[j - wt[ind]];
                }
                prev[j] = max(take, not_take);
            }
        }
        return prev[W];
	// Write your code here
}