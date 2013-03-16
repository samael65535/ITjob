#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <strings.h>

#define PORTNUM 6180
#define HOSTLEN 256

int main(int ac, char *argv[]){
  struct sockaddr_in saddr;
  struct hostent *hp;
  int sock_id;
  char buffer[BUFSIZ];
  memset(buffer, 0, sizeof(buffer));
  buffer[0] = '.';
  /* step 1 */
  sock_id = socket(AF_INET, SOCK_STREAM, 0);
  if(sock_id == -1)
    perror("socket");

  /* step 2 connect */
  bzero(&saddr, sizeof(saddr));
  hp = gethostbyname(argv[1]);;
  if(hp == NULL)
    perror("getname");
  bcopy(hp->h_addr, (struct sockaddr *)&saddr.sin_addr,
        hp->h_length);
  saddr.sin_port = htons(PORTNUM);
  saddr.sin_family = AF_INET;
  if(connect(sock_id, (struct sockaddr *)&saddr, sizeof(saddr)) != 0)
    perror("connect");
  /* step 3 read/write */
  if(write(sock_id, argv[2], strlen(argv[2])) == -1)
    perror("write");
  if(write(sock_id, "\n", 1) == -1)
    perror("write");
  printf("%d\n", sock_id);
  int  n_read;
  while((n_read = read(sock_id, buffer, BUFSIZ)) > 0){
    printf("%d\n", n_read);
    if(write(1, buffer, n_read) == -1)
      perror("write");
  }
  putchar('\n');
  /* step 4 close */
    close(sock_id);
  return 0;
}
