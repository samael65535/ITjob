#include<stdio.h>
/* 输出 100~200 的所有素数 */
int main()
{
  int num1[101], i, j, num2[201];
  for(i = 0; i < 101; i++){
    num1[i] = i + 100;
    num2[i] = i;
    num2[i + 100] = i + 100;
  }
  /* 方法一 判断每个数是不是素数 */
  int flag = 0;
  for(i = 0; i < 101; i++){
    for(j = 2; j * j <= num1[i]; j++){
      if(num1[i] % j == 0){
        flag = 1;
        break;
      }
    }
    if(flag == 0)
      printf("%d\t",num1[i]);
    flag = 0;
  }
  printf("\n\n");
  /* 方法二 筛法 */
  for(i = 2; i < 201; i++){
    for(j = 2; i * j < 201; j++)
      num2[i * j] = 0;
  }
  for(i = 100; i < 201; i++){
    if(num2[i] != 0)
      printf("%d\t",num2[i]);
  }
  printf("\n\n");
  /* 方法三 素数检查普遍公式 ??? */
  
  return 0;
}
