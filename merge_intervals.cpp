#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            if(intervals[i][0] <= ans.back()[1] && ans.back()[1] < intervals[i][1]){
                ans.back()[1] = intervals[i][1];
            }
            else if(intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    // Write your code here.
}
