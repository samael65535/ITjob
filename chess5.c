#include <stdio.h>
#include <string.h>
/* 命令行下的五子棋 */
/*  下一版本可以考虑用位实现  */
char table[17][17] = {
  "+++++++++++++++++",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+---------------+",
  "+++++++++++++++++",
};
void show_table()
{
  char a = 'a';
  printf("\t  ");
  for(; a <= 'o'; a++){
    putchar(a);
    putchar(' ');
  }
  printf("\n");
  int i = 0;
  for(; i <= 16; i++){
    if(i!=0 && i!= 16)
      printf("%d", i);
    printf("\t");
    int j = 0;
    for(; j <= 16; j++){
      putchar(table[i][j]);
      putchar(' ');
    }
    putchar('\n');
  }
}
int judge(int row, int col, int flag) /* 判断是否获胜, 黑1 平0 白-1 */
{
  int col_new_left, row_new_up, col_new_right, row_new_down;
  row_new_up = row - 5 > 0 ? row - 5 : 1;
  row_new_down = row + 5 < 16 ? row +5 : 16;
  
  col_new_left = col - 5 > 0 ? col - 5 : 1;
  col_new_right = col + 5 < 16 ? col + 5 : 16;
  int i, j;
  int count = 0;
  char chess = flag == 1 ? 'b' : 'w';
  /* 横 */
  for(i = col+1; i <= col_new_right; i++){
    if(table[row][i] == chess)
      count++;
    else
      break;
  }
  for(i = col; i >= col_new_left; i--){
    if(table[row][i] == chess)
      count++;
    else
      break;
  }
  printf("%d\n", count);
  if(count == 5)
    return flag;
  /* 竖 */
  count = 0;
  for(i = row+1; i <= row_new_down; i++){
    if(table[i][col] == chess)
      count++;
    else
      break;
  }
  for(i = row; i >= row_new_up; i--){
    if(table[i][col] == chess)
      count++;
    else
      break;
  }
  if(count == 5)
    return flag;
  /* 斜 */
  count = 0;
  j = col;
  for(i = row; i >= row_new_up; i--){
    if(table[i][j--] == chess)
      count++;
    else
      break;
  }
  j = col+1;
  for(i = row+1; i <= row_new_down; i++){
    if(table[i][j++] == chess)
      count++;
    else
      break;
  }
  if(count == 5)
    return flag;


  count = 0;
  j = col;
  for(i = row; i >= row_new_up; i--){
    if(table[i][j++] == chess)
      count++;
    else
      break;
  }
  j = col + 1;
  for(i = row+1; i <= row_new_down; i++){
    if(table[i][j--] == chess)
      count++;
    else
      break;
  }
  
  if(count == 5)
    return flag;
  return 0;
}

void put(int row, int col, int b_w)
{
  if(b_w == 1){
    table[row][col] = 'b'; 
  }else{
    table[row][col] = 'w';
   }
}

int main()
{
  int flag = 1;
  int row = 0, col = 0;
  show_table();
  while(1){
    if(flag == 1){              /* 黑子 */
      printf("put black:");
      scanf("%d%c", &row, &col);
      col = col - 'a' + 1;
      while(table[row][col] != '-'){
        printf("Wrong black\n");
        printf("put black: ");
        scanf("%d%c", &row, &col);
        col = col - 'a' + 1;
      }
      put(row, col, flag);
      show_table();
    }else{                      /* 白子 */
      printf("put white: ");
      scanf("%d%c", &row, &col);
      col = col - 'a' + 1;
      while(table[row][col] != '-'){
        printf("Wrong white\n");
        printf("put white: ");
        scanf("%d%c", &row, &col);
        col = col - 'a' + 1;
      }
      put(row, col, flag);
      show_table();
    }
    if(judge(row, col, flag) != 0)     /* 判断 */
      break;
    flag = flag * -1;
  }
  if(flag == 1)
    printf("black win\n");
  else if(flag == -1)
    printf("white win\n");
  return 0;
}
