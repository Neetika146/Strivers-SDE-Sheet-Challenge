#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &nums, int n)
{
        int index = -1;
        for (int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if (index == -1){
            sort(nums.begin(), nums.end());
            return nums;
        }
        for (int j = n-1; j > index; j--){
            if (nums[j] > nums[index]){
                swap(nums[j], nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());
        return nums;
}