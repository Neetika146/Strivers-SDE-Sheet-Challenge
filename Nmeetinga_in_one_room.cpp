//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    // bool isSorted(int end[], int n){
    //     for (int i = 1; i < n; i++){
    //         if (end[i-1] > end[i]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // void sortArray(vector <vector<int>> &arr, int n){
    //     for (int i = 1; i < n; i++){
            
    //     }
    // }
    int maxMeetings(int start[], int end[], int n)
    {
        pair <int, int> a[n];
        
        for (int i = 0; i < n; i++){
            a[i].first = end[i];
            a[i].second = i;
        }
        
        sort(a, a+n);
        
        int end_time = a[0].first;
        int count = 1;
        
        for (int i = 1; i < n; i++){
            if (start[a[i].second] > end_time){
                end_time = a[i].first;
                count++;
            }
        }
        
        return count;
        // // map <int, int> m;
        // // for (int i = 0; i < n; i++){
        // //     m[end[i]]=start[i];
        // // }
        // // // sort(m.begin(),m.end());
        // // int count = 1;
        // // int start_time = start[0];
        // // int end_time = end[0];
        // // for (auto i: m){
        // //     if (i.second > end_time){
        // //         end_time = i.first;
        // //         count++;
        // //     }
        // // }
        // // return count;
        // int count = 1;
        // vector <vector<int>> arr;
        
        // // arr.push_back(start[0]);
        // // arr.push_back(end[0]);
        // // for (int j = 0; j < n; j++){
        // // for (int i = 1; i < n; i++){
        // //     if(end[i-1] > end[i]){
        // //         swap(end[i-1], end[i]);
        // //         swap(start[i-1], start[i]);
        // //     }
        // //     if (i == n-1){
        // //         if(isSorted(end, n)){
        // //             break;
        // //         }
        // //         else{
        // //             i = 1;
        // //         }
        // //     }
        // // }
        // // }
        
        // for (int i = 0; i < n; i++){
        //     vector <int> temp = {start[i], end[i], i};
        //     arr.push_back(temp);
        // }
        // sortArray(arr, n);
        // int start_time = arr[0][0];
        // int end_time = arr[0][1];
        // for (int i = 1; i < n; i++){
        //     if (arr[i][0] > end_time){
        //         count++;
        //         end_time = arr[i][1];
        //     }
        // }
        
        // // for (int i = 1; i < n; i++){
        // //     if (arr[arr.size()-1] < start[i]){
        // //         count++;
        // //         arr.push_back(start[i]);
        // //         arr.push_back(end[i]);
        // //     }
        // // }
        // return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends