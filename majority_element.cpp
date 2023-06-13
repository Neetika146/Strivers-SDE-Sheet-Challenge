#include <bits/stdc++.h>

int findMajorityElement(int nums[], int n) {
	int element;
        int count = 0;
        // int n = nums.size();
        for(int i = 0; i < n; i++){
            if(count==0){
                count = 1;
                element = nums[i];
            }
            else if(element == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(element == nums[i]) ans++;
        }
        if(ans > n/2) return element;
        else return -1;
}