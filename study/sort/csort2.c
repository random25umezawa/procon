/*
 * C言語、構造体のソート
 */

#include <stdio.h>
#include <stdlib.h>

// 構造体の書き方の一つ
// typedef struct { ... } human;
// こう書くと int 等と同じように human を型として使える
typedef struct {
  char name[100];
  int height;
  int weight;
} human;

human arr[1000];

// human の height に関する比較関数
int comp_height(const void *a, const void *b) {
  return ((human*)a)->height-((human*)b)->height;
}

// human の weight に関する比較関数
int comp_weight(const void *a, const void *b) {
  return ((human*)a)->weight-((human*)b)->weight;
}

int main() {
  int n;
  scanf("%d",&n);
  printf("n = %d\n",n);

  printf("-----before-----\n");

  for(int i = 0; i < n; i++) {
    scanf("%s%d%d",&arr[i].name,&arr[i].height,&arr[i].weight);
    printf("%9s %5d %5d\n",arr[i].name,arr[i].height,arr[i].weight);
  }

  // ソート
  // #include <stdlib.h> が必要
  // qsort(対象の配列、要素数、要素一つのサイズ、比較関数)
  qsort(arr,n,sizeof(human),comp_height);

  printf("-----after-height-----\n");

  for(int i = 0; i < n; i++) {
  printf("%9s %5d %5d\n",arr[i].name,arr[i].height,arr[i].weight);
  }

  // ソート
  // #include <stdlib.h> が必要
  // qsort(対象の配列、要素数、要素一つのサイズ、比較関数)
  qsort(arr,n,sizeof(human),comp_weight);

  printf("-----after-weight-----\n");

  for(int i = 0; i < n; i++) {
  printf("%9s %5d %5d\n",arr[i].name,arr[i].height,arr[i].weight);
  }

  return 0;
}
