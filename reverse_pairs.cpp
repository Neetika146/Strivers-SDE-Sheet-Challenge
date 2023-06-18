#include <bits/stdc++.h> 
	void merge(vector<int>& nums, int low, int mid, int high, int &count){
        if(low >= high) return;


        int right = mid + 1;
        for(int i = low; i <= mid; i++){
            while( right <= high && nums[i] > 2 * (long long) nums[right]){
                right++;
            }
            count += right - (mid + 1);
        }


        int size = high - low + 1;
        vector <int> temp;
        int i = low, j = mid + 1, k = 0;
        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++, k++;
            }
            else{
                temp.push_back(nums[j]);
                j++, k++;
            }
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++, k++;
        }
        while(j <= high){
            temp.push_back(nums[j]);
            j++, k++;
        }
        
        int m = 0;
        for (int i = low; i <= high; i++){
            nums[i] = temp[m];
            m++;
        }
    }
    void mergesort(vector<int>& nums, int low, int high, int &count){
        if (low >= high) return;
        int mid = (high + low) / 2;
        mergesort(nums, low, mid, count);
        mergesort(nums, mid + 1, high, count);
        merge(nums, low, mid, high, count);

    }
    int reversePairs(vector<int>& nums, int n) {
        // int n = nums.size();
        int count = 0;
        mergesort(nums, 0, n-1, count);
        // long long count = 0;
        // for(int i = 0; i < n; i++){
        //     for (int j = i + 1; j < n; j ++){
        //         if(nums[i] > 2 * (long long) nums[j]) count++;
        //     }
        // }
        return count;
    }