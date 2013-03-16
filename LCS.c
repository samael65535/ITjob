#include<stdio.h>
#include<string.h>
/*
 * LCS 使用二维数组取最大公共子串
 */
int count[256][256];
int main()
{
  char str1[256];
  char str2[256];
  memset(count, 0, sizeof(count));
  printf("input str1\n");
  scanf("%s", str1+1);
  printf("input str2\n");
  scanf("%s", str2+1);
  int i, j, max = 0, max_i = 0, max_j = j;
  for(i = 1; i < strlen(str1); i++){
    for(j = 1; j < strlen(str2); j++){
      if(str1[i] == str2[j])
        count[i][j] = count[i-1][j-1] + 1;
      if(max < count[i][j]){
        max = count[i][j];
        max_i = i;
        max_j = j;
      }
      printf("%d\t", count[i][j]);
    }
    printf("\n");
  }
  char str3[256];
  memset(str3, 0, sizeof(str3));
  printf("%d %d\n", max_i, max_j);
  for(i = max; i > 0; i--)
    str3[i]=str2[max_j--];
  printf("%s\n", str3+1);
  return 0;
}
