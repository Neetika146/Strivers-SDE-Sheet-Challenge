long long getTrappedWater(long long* height, int n) {
        long long res = 0;
        int l = 0, r = n - 1, leftmax = 0, rightmax = 0;

        while(l <= r){

            if(height[l] <= height[r]){
                if(height[l] >= leftmax) leftmax = height[l];
                else res += leftmax - height[l];
                l++;
            }

            else{
                if(height[r] >= rightmax) rightmax = height[r];
                else res += rightmax - height[r];
                r--;
            }
        }
        return res;
    // Write your code here.
}