int cntfunc(vector<int> &arr, int mid){
    int l = 0, h = arr.size() - 1;
    while(l <= h){
        int md = (l + h) / 2;
        if(arr[md] <= mid) l = md + 1;
        else h = md - 1;
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 1;
    int high = 1e9;
    while(low <= high){
        int mid = (low + high) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += cntfunc(matrix[i], mid);
        }
        if(cnt <= (n*m)/2) low = mid +1;
        else high = mid - 1;
    }
    return low;
    // Write your code here.
}