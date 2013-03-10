#include<stdio.h>
// 测试用变量定义数组长度  GCC 不行  G++ 可以
int main()
{
  int N = 10;
  int a[N], i;
  for(i = 0; i < 10; i++)
    a[i] = i;
  N = 1;
  for(i = 0; i < 10; i++)
    printf("%d\t", a[i]);
  return 0; 
}
