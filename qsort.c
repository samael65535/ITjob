#include<stdio.h>
#define SWAP(x, y) x = (y + x) - (y = x) /* 交换 */
int part(int num[], int a, int b)        /* 输出key的位置 */
{
  int key = num[a];
  printf("%d\n", key);
  int i = a, j = b;
  do{
    while(num[j] >= key && i < j) j--;
    if(i < j)SWAP(num[j], num[i]);
    while(num[i] <= key && i < j) i++;
    if(i < j)SWAP(num[j], num[i]);
  }  while(i < j);
  return j;
}

int part2(int num[], int a, int b) /* 理解第二种方法? */
{
  int key = num[b];
  int j = a - 1;
  int i;
  for(i = a; i <= b-1; i++){
    if(num[i] <= key){
      j++;
      SWAP(num[i], num[j]);
    }
  }
  j++;
  SWAP(num[i], num[j]);
  return j;
}

void qsort(int num[], int a, int b)
{
  if(a >= b){
    return;
  }else if(a + 1 == b){
    if(num[a] > num[b])
      SWAP(num[a], num[b]);
    return;
  }
  int j = part2(num, a, b);
  qsort(num, a, j-1);
  qsort(num, j+1, b);
}

int main()
{
  int num[1000];
  int i;
  for(i = 0; i < 1000; i++){
    num[i] = 1000 - i;
  }
  qsort(num, 0, 999);
  for(i = 0; i < 1000; i++){
    printf("%d ", num[i]);
  }
  printf("\n");
  return 0;
}
