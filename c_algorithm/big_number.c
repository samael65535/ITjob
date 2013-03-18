#include <stdio.h>
#include <string.h>
#define MAX 100
/*
  big_number.out < big_number.in
  大数的加法
  大数的减法(假设 A > B, 会破坏原有数组的内容)
  大数与整型的乘法
  gcc下可以用变量定义数组长度
  记得处理 '0' 与'\0'  的区别
 */

void big_add(char *a, char *b, int *c, int *n)
{
  int len_a = strlen(a), len_b = strlen(b), len_c = 0;
  int num_a[MAX], num_b[MAX], v = 0;
  bzero(num_a, MAX * sizeof(num_a[0]));
  bzero(num_b, MAX * sizeof(num_b[0]));
  bzero(c, MAX * sizeof(c[0]));
  len_c = len_a > len_b ? len_a : len_b;
  int i;
  *n = len_c;
  for(i = 0; i < len_a; i++){
    num_a[i] = a[len_a - i - 1] - '0';
  }
  for(i = 0; i < len_b; i++){
    num_b[i] = b[len_b - i - 1] - '0';
  }
  for(i = 0; i < len_c; i++){
    int tmp = num_a[i] + num_b[i] + v;
    c[i] = tmp % 10;
    v = tmp / 10;
  }
  if(v != 0){
    *n = len_c + 1;
    c[len_c] = v;
  }
}

void big_sub(char *a, char *b, int *c, int *n)
{
  int len_a = strlen(a), len_b = strlen(b), len_c = 0;
  int num_a[MAX], num_b[MAX], v = 0, i;
  bzero(num_a, MAX * sizeof(num_a[0]));
  bzero(num_b, MAX * sizeof(num_b[0]));
  bzero(c, MAX * sizeof(c[0]));
  len_c = len_a > len_b ? len_a : len_b;
  for(i = 0; i < len_a; i++){
    num_a[i] = a[len_a - i - 1] - '0';
  }
  for(i = 0; i < len_b; i++){
    num_b[i] = b[len_b - i - 1] - '0';
  }
  for(i = 0; i < len_c; i++){
    int tmp = num_a[i] - num_b[i];
    if(num_a[i] - num_b[i] < 0){
      c[i] = num_a[i] - num_b[i] + 10;
      --num_a[i+1];
    }else{
      c[i] = num_a[i] - num_b[i];
    }
  }
  v = 0;
  for(i = len_c; i >= 0; i--){
    if(c[i] != 0) v = 1;
    if(v == 1) (*n)++;
  }
}

void big_mulit(char *a, int b, int *c, int *n)
{
  int len_a = strlen(a), len_c = 0;
  int num_a[MAX], num_b[MAX], v = 0, i;
  bzero(num_a, MAX * sizeof(num_a[0]));
  bzero(c, MAX * sizeof(c[0]));
  for(i = 0; i < len_a; i++){
    num_a[i] = a[len_a - i - 1] - '0';
  }
  for(i = 0; i < MAX; i++){
    int tmp = num_a[i] * b + v;
    c[i] = tmp % 10;
    v = tmp / 10;
  }
  v = 0;
  for(i = MAX - 1; i >= 0; i--){
    if(c[i] != 0) v = 1;
    if(v == 1) (*n)++;
  }
}

int main()
{
  char a[MAX], b[MAX];
  int c[MAX], n, i, x;
  bzero(a, sizeof(a));
  bzero(b, sizeof(b));
  bzero(c, sizeof(c));
  scanf("%s", a);
  scanf("%s", b);
  x = atoi(b);

  n = 0;
  big_add(a, b, c, &n);
  for(i = n-1; i >= 0; i--)
    printf("%d", c[i]);
  printf("\tadd N:%d\n", n);

  n = 0;
  big_mulit(a, x, c, &n);
  for(i = n-1; i >= 0; i--)
    printf("%d", c[i]);
  printf("\t mulit N:%d\n", n);

  n = 0;
  big_sub(a, b, c, &n);
  for(i = n-1; i >= 0; i--)
    printf("%d", c[i]);
  printf("\t sub N:%d\n", n);

  return 0;
}
