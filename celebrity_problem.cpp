#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int> st;
	for(int i = 0; i < n; i++){
		st.push(i);
	}
	while(st.size() > 1){
		int x = st.top();
		st.pop();
		int y = st.top();
		st.pop();
		if(knows(y, x)){
			st.push(x);
		}
		else{
			st.push(y);
		}
	}
	int ans = st.top();
	for(int i = 0; i < n; i++){
		if(ans != i && !knows(i, ans) || knows(ans, i)) return -1;
	}
	return ans;
 	// Write your code here.
}