int calculateMinPatforms(int arr[], int dep[], int n) {
    sort(arr, arr + n);
        sort(dep, dep + n);
        
        int platform_needed = 1, result = 1;
        int i = 1, j = 0;
        
        while (i < n && j < n){
            if (arr[i] <= dep[j]){
                platform_needed++;
                i++;
            }
            else if (arr[i] > dep[j]){
                platform_needed--;
                j++;
            }
            if (platform_needed > result){
                result = platform_needed;
            }
        }
        return result;
}