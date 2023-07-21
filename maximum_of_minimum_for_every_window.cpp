#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> arr, int n) {
        // int n = arr.size();
        stack<int> st;
        vector<int> leftSmall(n, -1), rightSmall(n, n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) leftSmall[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) rightSmall[i] = st.top();
            st.push(i);
        }
        vector<int> ans(n, INT_MIN);
        for(int i = 0; i < n; i++){
           ans[rightSmall[i] - leftSmall[i] - 2] = max(ans[rightSmall[i] - leftSmall[i] - 2], arr[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        return ans;
    // Write your code here.
}