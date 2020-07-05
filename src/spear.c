#include <stdio.h>

int n;
int k;
int A[100000];

// 判別用関数
int p(int x){
  int i,sum;
  sum = 0;
  if(x == 0) return 0;   // 0で割れないので分岐させて処理
  else {
    for(i=0;i<n;i++) sum += A[i] / x; 
  }
  return sum < k;
}



int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0; 
  ub = 1000000000; // a_i<=10^9

  while(ub - lb > 1) { 
    int mid = (lb + ub) / 2; 

    if(p(mid)) ub = mid; 
    else  ub = mid; 
  }
  
  printf("%d\n", ub);

  return 0;
}
