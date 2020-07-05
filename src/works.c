#include <stdio.h>

int n;
int k;
int A[100000];

// ���ʗp�֐�
// �e�l���d���ʂ̏���܂Ŏd�����A����őS�Ă̎d���������o�����琬��
int p(int x){
  int i, j;
  j = 0;
  int B[k];
  for(i = 0; i < k; i++){
    B[i] = 0;
    while (1){
      if (B[i] + A[j] >= x) break; // �K��̎d���ʂɒB�������ȏꍇ�A���̑O�ɏI�����Ď���
      B[i] += A[j];
      j++;
      if(j==n) return 1;  // �d����S���U�ꂽ�̂�1(true)���o��
    }
  }
  return 0; // �d�����I���Ȃ������̂�0(false)���o��
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0; 
  ub = 1000000001; // a_i�͍ő�10^4*10^5=10^9���o�͂�lb

  while(ub - lb > 1) { 
    int mid = (lb + ub) / 2; 

    if(p(mid)) ub = mid; 
    else  lb = mid; 
  }
  
  printf("%d\n", lb);

  return 0;
}
