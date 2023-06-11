#include <bits/stdc++.h>

long long merge(long long *arr, int low, int mid, int high) {
    // if (low >= high) return 0;

    vector <long long> temp;
    long long count = 0;
    int left = low, right = mid + 1;
    while (left <=mid && right <= high){
        if(arr[left]> arr[right]){
            temp.push_back(arr[right]);
            right++;
            count += mid - left + 1;
        }
        else{
            temp.push_back(arr[left]);
            left++;
        }
    }
    while (left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
        // count += mid - left + 1;
    }
    for (int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }

    return count;
}
long long mergeSort(long long *arr, int low, int high){
    if (low >= high) return 0;
    long long count = 0;
    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);


    // long long ans = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++){
    //         if(arr[i] > arr[j]){
    //             ans++;
    //         }
    //     }
    // }
    // return ans;
}