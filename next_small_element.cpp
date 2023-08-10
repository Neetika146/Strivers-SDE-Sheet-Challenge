#include <stack>
#include <bits/stdc++.h>
vector<int> Solution::prevSmaller(vector<int> &nums) {
    int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i =  0; i < n; i++) {
        while (!st.empty() && st.top() >= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
}