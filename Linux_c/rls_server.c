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
/*
* 远程LS 服务端
*/
void sanitize(char *str)
{
  char *src, *dest;
  for(src = dest = str; *src; src++)
    if(*src == '/' || isalnum(*src))
      *dest++ = *src;
  *dest = '\0';
}

int main(int ac, char *argv){
  struct sockaddr_in saddr;
  struct hostent *hp;
  char hostname[HOSTLEN];
  memset(hostname, 0, sizeof(hostname));
  int sock_id, sock_fd;
  FILE *sock_fpi, *sock_fpo;
  FILE *pipe_fp;
  char direname[BUFSIZ];
  memset(direname, 0, sizeof(direname));
  char command[BUFSIZ];
  memset(command, 0, sizeof(command));
  int dirlen, c;
  /* step 1 socket*/
  sock_id = socket(PF_INET, SOCK_STREAM, 0);
  if(sock_id == -1)
    perror("socket");

  /* step 2 bind*/
  bzero((void *)&saddr, sizeof(saddr));
  gethostname(hostname, HOSTLEN);
  hp = gethostbyname(hostname);
  bcopy((void *)hp->h_addr, (void *)&saddr.sin_addr, hp->h_length);
  saddr.sin_port = htons(PORTNUM);
  saddr.sin_family = AF_INET;
  
  if(bind(sock_id, (struct sockaddr *)&saddr, sizeof(saddr)) != 0)
    perror("bind");

  /* step 3 listen */
  if(listen(sock_id, 1) != 0)
    perror("listen");

  /* step 4 accept */
  while(1){
    sock_fd = accept(sock_id, NULL, NULL);
    if(sock_fd == -1)
      perror("sock_fd");

    if((sock_fpi = fdopen(sock_fd, "r")) == NULL)
      perror("fdopen");

    if(fgets(direname, BUFSIZ - 5, sock_fpi) == NULL)
      perror("fgets");
    sanitize(direname);
    sprintf(command,"ls %s", direname);

    if((pipe_fp = popen(command, "r")) == NULL)
      perror("popen");
    if((sock_fpo = fdopen(sock_fd, "w")) == NULL){
      perror("write");
    }
    /* printf("%d\n", sock_fpo); */
    /* printf("%d\n", sock_fpi); */
    while((c = getc(pipe_fp)) != EOF){   
      putchar(c);
      putc(c, sock_fpo);        /*client    D */
    }
    pclose(pipe_fp);
    fclose(sock_fpo);
    fclose(sock_fpi);
  }
  return 0;
}
