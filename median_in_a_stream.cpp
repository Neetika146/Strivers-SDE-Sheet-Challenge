#include<bits/stdc++.h>
class MedianFinder {
public:
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 || maxHeap.top() >= num){
            maxHeap.push(num);
        }
        else minHeap.push(num);

        if(maxHeap.size() < minHeap.size()){
            int ele = minHeap.top();
            minHeap.pop();
            maxHeap.push(ele);
        }
        else if(maxHeap.size() > minHeap.size() + 1){
            int ele = maxHeap.top();
            maxHeap.pop();
            minHeap.push(ele);
        }
    }
    
    int findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }
        return maxHeap.empty() ? 0 : floor(maxHeap.top() + minHeap.top())/2;
    }
};
vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	MedianFinder m;
	for(int i = 0; i < n; i++){
		m.addNum(arr[i]);
		ans.push_back(m.findMedian());
	}
	return ans;
	// Write your code here 
}
