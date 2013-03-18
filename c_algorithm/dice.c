#include <stdio.h>
#include <string.h>
#define MAX 4
/*
  dice.out < dice.in
  判断两个色子是否是相同型号的
  面的定义:
                        2
                       /
                      v 
         +---------+
        /   1     /|
       /         / |
       +--------+  |
       |        |5 |
  4 -> |   0    |  |
       |        |  +
       |        | /
       +--------+
          ^
          |
          3

  只翻转一个色子一定有一个状态和另一人一样          
 */
void horizontal(int *dice)      /* 水平翻转一次 向左*/
{
  int tmp = dice[0], i;
  dice[0] = dice[5];
  dice[5] = dice[2];
  dice[2] = dice[4];
  dice[4] = tmp;
  printf("horizontal\n");
  for(i = 0; i < 6; i++){
    printf("%d", dice[i]);
  }
  putchar('\n');

}

void vertical(int *dice)        /* 垂直翻转一次  向下 */
{
  int tmp = dice[0], i;
  dice[0] = dice[1];
  dice[1] = dice[2];
  dice[2] = dice[3];
  dice[3] = tmp;
  printf("vectical\n");
    for(i = 0; i < 6; i++){
    printf("%d", dice[i]);
  }
  putchar('\n');

}

void clockwise(int *dice)       /* 顺时针翻转一次 */
{
  int tmp = dice[1], i;
  dice[1] = dice[4];
  dice[4] = dice[3];
  dice[3] = dice[5];
  dice[5] = tmp;
      printf("clockwise\n");
  for(i = 0; i < 6; i++){
    printf("%d", dice[i]);
  }
  putchar('\n');
}

int judge(int *dice1, int *dice2)
{
  int i = 0;
  for(i = 0; i < 6; i++){
    if(dice1[i] != dice2[i])
      return 0;
  }
  return 1;
}
int main()
{
  int dice1[6], dice2[6];
  int i = 0, is_same = 0, j = 0;
  for(i = 0; i < 6; i++){
    scanf("%d", &dice1[i]);
    printf("%d\t", dice1[i]);
  }
  printf("\n");
  for(i = 0; i < 6; i++){
    scanf("%d", &dice2[i]);
    printf("%d\t", dice2[i]);
  }
  printf("\n");
  for(j = 0; j < 4; j++){
    vertical(dice1);
    if(is_same == 0)
      is_same = judge(dice1, dice2);
    for(i = 0; i < 4; i++){
      horizontal(dice1);
      if(is_same == 0)
        is_same = judge(dice1, dice2);
    }
    vertical(dice1);
    for(i = 0; i < 4; i++){
      clockwise(dice1);
      if(is_same == 0)
        is_same = judge(dice1, dice2);
    }
  }
  if(is_same == 0)
    printf("\nNO\n");
  else
    printf("\nYES\n");
  return 0;
}








