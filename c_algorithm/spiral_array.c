#include <stdio.h>
#include <string.h>
#define MAX 4
/*
 输出螺旋数组 注意奇偶数1的位置
 */
int main()
{
  int spiral[MAX][MAX], mid = MAX / 2;
  int s = 1, xi = 1, k = 1, a = 0, b = 0;
  int i = mid, j = mid;
  bzero(spiral, sizeof(spiral));
  while(s <= MAX * MAX){
    for(xi = 1; xi <= k && s <= MAX * MAX; xi++)
      spiral[i][j--] = s++;     /* <- */
    for(xi = 1; xi <= k && s <= MAX * MAX; xi++)
      spiral[i--][j] = s++;     /* ^ */
    if(k < MAX) k++;
    for(xi = 1; xi <= k && s <= MAX * MAX; xi++)
      spiral[i][j++] = s++;     /* -> */
    for(xi = 1; xi <= k && s <= MAX * MAX; xi++)
      spiral[i++][j] = s++;     /* v */
    if(k < MAX) k++;
  }
  for(i = 0; i < MAX; i++){
    for(j = 0; j < MAX; j++){
      printf("%d\t", spiral[i][j]);
    }
    putchar('\n');
  }

  return 0;
}





