#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
/* 服务器:
 * 1. 获取电话线   socket
 * 2. 分配号码   bind
 * 3. 允许接入调用   listen
 * 4. 等待电话   accept
 * 5. 传送数据  read
 * 6. 挂断电话   close
 */
#define USEPORT 6180
int main(int argc, char *argv)
{
  struct sockaddr_in saddr;
  struct hostent *hp;
  char hostname[200];
  int sock_id, sock_fd;
  FILE* sock_fp;
  time_t thetime;
  
  /* step 1 */
  sock_id = socket(PF_INET, SOCK_STREAM, 0);
  if(sock_id == -1)
    perror("sock_id");

  /* step 2 */
  bzero((void *)&saddr, sizeof(saddr));
  bzero((void *)hostname, sizeof(hostname)); /* 注意, 要清零非则会产生错误 core dump */
  gethostname(hostname, sizeof(hostname));
  hp = gethostbyname(hostname);
  printf("%s\n", hostname);
  bcopy((void *)hp->h_addr, (void *)&saddr.sin_addr, hp->h_length);

  saddr.sin_port = htons(USEPORT);
  saddr.sin_family = AF_INET;

  if(bind(sock_id, (struct sockaddr *)&saddr, sizeof(saddr)) != 0)
    perror("bind");

  /* step 3 */
  if(listen(sock_id, 1) != 0)
    perror("listen");

  while(1){
    sock_fd = accept(sock_id, NULL, NULL);
    printf("hello\n");
    if(sock_fd == -1)
      perror("accept");
    sock_fp = fdopen(sock_fd, "w");
    if(sock_fp == NULL)
      perror("fdopen");

    thetime = time(NULL);

    fprintf(sock_fp, "the time is ");
    fprintf(sock_fp, "%s", ctime(&thetime));
    fclose(sock_fp);
  }
  return 0;
}










