#include<stdio.h>
/* 使用指针的指针指向二维数组 */
int main()
{
  int a[3][3], i, j;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      a[i][j] = i * 3 + j;
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  int **p = a;

  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      printf("%d\t", *(p + i*3 + j)); /* ? */
    }
    printf("\n");
  }
}
