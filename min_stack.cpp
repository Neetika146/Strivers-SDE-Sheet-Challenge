#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		stack<pair<int,int>> st;
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		void push(int val) {
			if(st.empty()) st.push({val, val});
			else st.push({val, min(val, st.top().second)});
		}
		
		int pop() {
			if(st.empty()) return -1;
			int ans = st.top().first;
			st.pop();
			return ans;
		}
		
		int top() {
			if(st.empty()) return -1;
			return st.top().first;
		}
		
		int getMin() {
			if(st.empty()) return -1;
			return st.top().second;
		}
};