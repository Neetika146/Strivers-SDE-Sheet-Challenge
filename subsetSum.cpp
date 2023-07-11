void helper(vector<int> &arr, int N, int sum, int i, vector <int> &ans){
        if(i == N){
            ans.push_back(sum);
            return;
        }
        helper(arr, N, sum + arr[i], i+1, ans);
        helper(arr, N, sum, i+1, ans);
}
vector<int> subsetSum(vector<int> &arr){
		int N = arr.size();
		vector <int> ans;
        helper(arr, N, 0, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
	// Write your code here.	
}