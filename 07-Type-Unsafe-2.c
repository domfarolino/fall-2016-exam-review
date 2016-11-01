/* Do this:  typ-unsafe-2 2134507666 */
/* paraphrase of actual bug in the wild - SSHD casting vulnerability */
#include <stdio.h>
#include <stdlib.h>
#include <climits>

#define PRIVILEGED_PORT 1024

typedef struct { unsigned short port; } net;

int main (int argc, char **argv) {
   int port;
   net bin;

   if (argc != 2) {
      printf("Usage: %s <port-number>\n",argv[0]);
      exit(0);
   }

   port = atoi(argv[1]);

   printf("INT_MAX: %i", INT_MAX);

   printf("Port: %d\n", port);

   //328000

   if (port < PRIVILEGED_PORT) {
      printf("Users are not granted permission to use ports 0-1023\n");
      exit(0);
   }

   bin.port = port;
   printf("The OS gave you port %d\n", bin.port);
}
