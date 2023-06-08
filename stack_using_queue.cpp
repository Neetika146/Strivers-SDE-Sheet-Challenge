#include <bits/stdc++.h> 
class Stack {
	// Define the data members.

   public:
    queue <int> q1;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.size()==0;
    }

    void push(int x) {
        q1.push(x);
        for(int i = 1; i < q1.size(); i++){
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop() {
        if(q1.size() == 0){
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top() {
        if(q1.size() == 0){
            return -1;
        }
        return q1.front();
    }
};