/*
 ============================================================================
 Name    : client.c
 Author   : king
 Version   :
 Copyright  : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> /* inet(3) functions */

int handle(int fd);

int main(void)
{
  int nsd;
  char buf[1024];

  char *myaddr = "127.0.0.1";
  struct sockaddr_in addr;

  printf("welcome to echo client\n");
  nsd = socket(AF_INET, SOCK_STREAM, 0);
  printf("connect start1 \n");
  //bzero(addr, sizeof(*addr));
  memset(&addr, 0, sizeof(addr));
  printf("connect start2 \n");
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8888);
  addr.sin_addr.s_addr = inet_addr(myaddr);

  printf("connect start3 \n");
  if (connect(nsd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0)
  {
    printf("connect error \n");
    return -1;
  }

  sleep(5);
  printf("handle start\n");
  handle(nsd);
  close(nsd);
  return EXIT_SUCCESS;
}

int handle(int fd)
{

  char sendl[1024], rev[1024];
  int retn;

  for (;;)
  {
    memset(sendl, 0, sizeof(sendl));
    memset(rev, 0, sizeof(rev));
    if (fgets(sendl, 1024, stdin) == NULL)
    {
      break;
    }
    //
    printf("wirte start\n");
    write(fd, sendl, strlen(sendl));
    read(fd, rev, strlen(rev));
  }
  return 0;
}