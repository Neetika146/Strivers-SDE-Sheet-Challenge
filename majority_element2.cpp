#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &nums)
{
        int element1, element2;
        int count1 = 0, count2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(count1==0 && nums[i] != element2){
                count1 = 1;
                element1 = nums[i];
            }
            else if(count2==0 && nums[i] != element1){
                count2 = 1;
                element2 = nums[i];
            }
            else if(element1 == nums[i]){
                count1++;
            }
            else if(element2 == nums[i]){
                count2++;
            }
            else{
                count1--, count2--;
            }
        }
        vector <int> arr;
        int ans1 = 0;
        for(int i = 0; i < n; i++){
            if(element1 == nums[i]) ans1++;
        }
        int ans2 = 0;
        for(int i = 0; i < n; i++){
            if(element2 == nums[i]) ans2++;
        }
        if(ans1 > n/3) {
            arr.push_back(element1);
        }
        if(ans2 > n/3) {
            arr.push_back(element2);
        }
        return arr;
    // Write your code here.

}