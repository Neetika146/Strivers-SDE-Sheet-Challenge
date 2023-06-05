#include <bits/stdc++.h>

int findMajorityElement(int nums[], int n) {
		map <int, int> m;
        int ans = 0;
        for (int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        for (auto i: m){
            if(i.second > n/2){
                return i.first;
            }
        }
        return -1;
}