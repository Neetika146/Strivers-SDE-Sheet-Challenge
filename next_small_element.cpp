#include <stack>
#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &A, int n)
{
    vector <int> ans;
    stack <int> st;
    for (int i = n-1; i >=0; i--){
        while(!st.empty() && A[i] <= st.top()){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        st.push(A[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}