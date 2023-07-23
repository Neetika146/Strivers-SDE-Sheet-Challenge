#include <bits/stdc++.h> 
int compareVersions(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();
        long l1, l2;
        while(i < n || j < m){
            l1 = 0;
            l2 = 0;
            while(i < n && version1[i] != '.'){
                l1 = l1 * 10 + (version1[i] - '0');
                i++;
            }
            while(j < m && version2[j] != '.'){
                l2 = l2 * 10 + (version2[j] - '0');
                j++;
            }
            if(l1 > l2){
                return 1;
            }
            else if( l1 < l2){
                return -1;
            }            
            i++;
            j++;
        }
        return 0;
}

 