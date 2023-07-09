#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());
        int cnt = 1;
        int ans = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    cnt++;
                } 
                else {
                    cnt = 1;
                }
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
// #include <bits/stdc++.h>

// int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
//     map <int, int> m;
//         if (nums.size() == 0){
//             return 0;
//         }
//         for (int i = 0; i < nums.size(); i++){
//             m[nums[i]]++;
//         }
//         int ans = 0;
//         int curr = 0;
//         for (auto i: m){
//             if(m.find(i.first+1) != m.end()){
//                 curr++;
//             }
//             else{
//                 curr = 0;
//             }
//             ans = max(ans, curr);
//         }
//         return ans+1;
// }