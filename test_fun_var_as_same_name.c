#include<stdio.h>
/* 测试函数名与变量名相同 */
int fun2 = 2;
int fun1()
{
  printf("dd\n" );
  return 0;
}
int main()
{
  int fun1 = 1;
  int main = 1;

  return 0;
}
int fun2()
{
  return 0;
}
