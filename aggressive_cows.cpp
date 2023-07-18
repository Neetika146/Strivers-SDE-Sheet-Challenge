#include <bits/stdc++.h>
bool canWePlace(vector<int> positions, int mid, int c) {
	int players = 1, last = positions[0];
	for(int i = 1; i < positions.size(); i++){
		if(positions[i] - last >= mid){
			players++;
			last = positions[i];
		}
		if(players == c) return true;
	}
	return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());
	int low = 1, high = positions[n-1] - positions[0];
	while(low <= high){
		int mid = ( low + high) / 2;
		if(canWePlace(positions, mid, c)){
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return high;
	// Write your code here
}