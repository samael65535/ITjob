#include<stdio.h>
/*
   A:不是我
   B:是C
   C:是D
   D:C乱说
   三人说真话, 求小偷
   解法2:
   类似求交集
   提示A: 0111 之后假设某个人说假话
 */
int main()
{
  /* 解法一  */
  int i, j;
  for(i = 1; i < 5; i++){
    if((i!=1) + (i==3) + (i==4) + (i!=4) == 3)
      printf("%c\n", i+96);
  }

  /* 解法二 */
  int s[5] = {0, 7, 2, 1, 14};
  for(i = 1; i < 4; i++){
    int tmp = s[i], res = 0;
    s[i] = 15 - s[i];
    int k = s[1] & s[2] & s[3] & s[4];
    if(k != 0){
      switch(k){
      case 8 : printf("a\n");break;
      case 4 : printf("b\n");break;
      case 2 : printf("c\n");break;
      case 1 : printf("d\n");break;
      }
    }
    s[i] = tmp;
  }
}
