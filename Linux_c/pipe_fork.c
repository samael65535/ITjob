#include <stdio.h>
#include <unistd.h>
#include <string.h>
/* 使用fork进行共享管道
 * 当进程创建一个管道之后, 该进程就有了连向管道两端的连接.当这个进程调用fork的时候, 它的子进程也得到了两个连向管道的连接.
 * parent <==> child
 *
 */

int main()
{
  int pipe_fork[2];
  int len_buf1, len_buf2;
  char buf1[] = "hello from child";
  char buf2[17];
  if(pipe(pipe_fork) == -1){
    perror("error");
  }
  len_buf1 = strlen(buf1);
  if(fork()){
    while(1){
      read(pipe_fork[0], buf2, len_buf1);
      printf("in parent  %s\n", buf2);
      sleep(1);
    }
  }else{
    while(1){
      write(pipe_fork[1], buf1, len_buf1);
      sleep(1);
    }
  }
  return 0;
}
