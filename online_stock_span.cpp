#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &prices) {
    vector<int> ans;
    stack<pair<int, int>> st;
    for(auto price: prices){
    if(st.empty() || (!st.empty() && st.top().first > price)) st.push({price, 1});
        else {
            int x = 0;
            while(!st.empty() && st.top().first <= price){
                x += st.top().second;
                st.pop();                
            }
            st.push({price, x + 1});
        }
        ans.push_back(st.top().second);
    }
    return  ans;
    // Write your code here.
}