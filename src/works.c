#include <stdio.h>

int n;
int k;
int A[100000];

// 判別用関数
// 各人が仕事量の上限まで仕事し、それで全ての仕事が完了出来たら成功
int p(int x){
  int i, j;
  j = 0;
  int B[k];
  for(i = 0; i < k; i++){
    B[i] = 0;
    while (1){
      if (B[i] + A[j] >= x) break; // 規定の仕事量に達しそうな場合、その前に終了して次へ
      B[i] += A[j];
      j++;
      if(j==n) return 1;  // 仕事を全部振れたので1(true)を出力
    }
  }
  return 0; // 仕事が終わらなかったので0(false)を出力
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0; 
  ub = 1000000001; // a_iは最大10^4*10^5=10^9かつ出力はlb

  while(ub - lb > 1) { 
    int mid = (lb + ub) / 2; 

    if(p(mid)) ub = mid; 
    else  lb = mid; 
  }
  
  printf("%d\n", lb);

  return 0;
}
