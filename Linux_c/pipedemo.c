#include <stdio.h>
#include <unistd.h>
#include <string.h>
/* 测试管道
 * 函数原型:
 * int pipe(int array[2])
 * array[1]写入端  array[0] 读取端 
 */
int main()
{
  int test_pipe[2];
  if(pipe(test_pipe) == -1){
    perror("errer pipe");
  }
  printf("%d   %d\n", test_pipe[0], test_pipe[1]);

  char str[] = "test pipe";
  int len = strlen(str);
  write(test_pipe[1], str, len);
  char str2[10];
  read(test_pipe[0], str2, len);
  printf("%s\n",  str2);
  return 0;
}
