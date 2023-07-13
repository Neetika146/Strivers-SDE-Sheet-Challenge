double multiply (double number, int n){
  double ans = 1.0;
  for (int i = 1; i <= n; i++){
    ans = ans * number;
  }
  return round(ans);
}

int NthRoot(int n, int m) {
  // int ans = 1;
  // int count = 0;
  // while (ans <= m){
  //   ans = ans * n;
  //   count++;
  //   if(ans == m){
  //     return count;
  //   }
  // }
  // return -1;


  int low = 1, high = m;
  while(low <= high){
    int mid = (low + high) / 2;
    if(pow(mid,n) == m) {
      return mid;
    }
    else if(pow(mid,n) < m){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return -1;





  // double low = 1, high = m;
  // double eps = 1e-6;

  // while((high-low)>eps){
  //   double mid = (high + low) / 2;
  //   if(multiply(mid, n) == m){
  //     return mid;
  //   }
  //   else if(multiply(mid, n) < m){
  //     low = mid;
  //   }
  //   else{
  //     high = mid;
  //   }
  // }
  // return -1;
}