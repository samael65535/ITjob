#include<stdio.h>
/* 测试 字符型数组 a[2][3] = {"a", ' ', "b"} 的输出 */
int main()
{
  char a[2][3] = {"a", ' ', "b"};
  int i;
  for(i = 0; i < 2; i++)
    printf("%s\n", a[i]);
}
