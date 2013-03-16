#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
/* 客户端:
 * 1. 获取一根电话线    socket
 * 2. 呼叫服务器  connect
 * 3. 传送数据   read/ write
 * 4. 挂断电话  close
 */
int main(int argc, char *argv[])
{
  struct sockaddr_in servadd;
  struct hostent *hp;
  int sock_id, sock_fd;
  char  message[BUFSIZ];
  int messlen = 0;
  
  bzero((void *) message, sizeof(message));
  /* step 1 */
  sock_id = socket(AF_INET, SOCK_STREAM, 0);
  if(sock_id == -1)
    perror("socket");
  /* step 2 */
  bzero(&servadd, sizeof(servadd));
  hp = gethostbyname(argv[1]);
  if(hp == NULL)
    perror(argv[1]);
  bcopy(hp->h_addr, (struct sockaddr *)&servadd.sin_addr, hp->h_length);
  servadd.sin_port = htons(atoi(argv[2]));
  servadd.sin_family = AF_INET;

  if(connect(sock_id, (struct sockaddr *) &servadd, sizeof(servadd)) != 0)
    perror("connect");
  /* step 3 */
  messlen = read(sock_id, message, BUFSIZ);
  if(messlen == -1)
    perror("read");
  if(write(1, message, messlen) != messlen)
    perror("message");

  close(sock_id);
  return 0;
}










