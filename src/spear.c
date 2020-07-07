#include <stdio.h>

int n;
int k;
int A[100000];

// ���ʗp�֐�
int p(int x){
  int i,sum;
  sum = 0;
  for(i=0;i<n;i++) sum += A[i] / x; 
  return sum < k;
}



int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0; 
  ub = 1000000001; // a_i<=10^9���o�͂�lb

  while(ub - lb > 1) { 
    int mid = (lb + ub) / 2; 

    if(p(mid)) ub = mid; 
    else  lb = mid; 
  }
  
  printf("%d\n", lb);
  return 0;
}
