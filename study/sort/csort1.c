/*
 * C言語、単純に整数列をソートする場合
 */

#include <stdio.h>
#include <stdlib.h>

int arr[1000];

// 比較関数
int comp(const void *a, const void *b) {
  return *(int*)a-*(int*)b;
}

int main() {
  int n;
  scanf("%d",&n);
  printf("n = %d\n",n);

  printf("-----before-----\n");

  // 読み込み
  for(int i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
    printf("%d\n",arr[i]);
  }

  // ソート
  // #include <stdlib.h> が必要
  // qsort(対象の配列、要素数、要素一つのサイズ、比較関数)
  qsort(arr,n,sizeof(int),comp);

  printf("-----after-----\n");

  for(int i = 0; i < n; i++) {
    printf("%d\n",arr[i]);
  }

  return 0;
}
