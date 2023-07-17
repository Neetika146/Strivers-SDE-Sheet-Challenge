#include <bits/stdc++.h> 
bool allocateisPossible(long long &barrier, int &k, int n, vector<int> &time){
	long long stu = 1, pages = 0;
	for(int i = 0; i < n; i++){
		if(time[i] > barrier) return false;
		if(pages + time[i] > barrier) {
			stu += 1;
			pages = time[i];
		}
		else pages += time[i];
	}
	if(stu > k) return false;
	return true;
}
long long ayushGivesNinjatest(int k, int n, vector<int> time) 
{	
	long long low = 1;
	long long high = LONG_MAX;
	while(low <= high){
		long long mid = (low + high) >> 1;
		if(allocateisPossible(mid, k, n, time)){
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return low;
	// Write your code here.
} 