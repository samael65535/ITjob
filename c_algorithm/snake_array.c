#include <stdio.h>
#include <string.h>
#define MAX 5
/*
 输出蛇形数组 注意边界的判断
 */
int main()
{
  int snake[MAX][MAX];
  bzero(snake, sizeof(snake));
  int i = 0, s = 0, j = 0, flag = 0;
  do{
    for(j = 0; j < MAX && i < MAX; j++)
      snake[i][j] = ++s;
    i++;
    for(j = MAX-1; j >=0 && i < MAX; j--)
      snake[i][j] = ++s;
    i++;
  }while(i < MAX);                /* 注意i++的次数 */
  for(i = 0; i < MAX; i++){
    for(j = 0; j < MAX; j++){
      printf("%d\t", snake[i][j]);
    }
    putchar('\n');
  }
  return 0;
}
