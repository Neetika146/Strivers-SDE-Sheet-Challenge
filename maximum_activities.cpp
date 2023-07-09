#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &end) {
    int n = start.size();
    pair <int, int> a[n];
        
        for (int i = 0; i < n; i++){
            a[i].first = end[i];
            a[i].second = i;
        }
        
        sort(a, a+n);
        
        int end_time = a[0].first;
        int count = 1;
        
        for (int i = 1; i < n; i++){
            if (start[a[i].second] >= end_time){
                end_time = a[i].first;
                count++;
            }
        }
        
        return count;
}