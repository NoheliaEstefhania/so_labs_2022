#include <sys/types.h>
#include <wait.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#define MAX 10
char *frase = "Mensaje del proceso padre al hijo. FIN" ;
int main () {
  int fd[2] ; // Array para almacenar los descriptores del pipe
  int pid ;
  char buffer[MAX] ; // Buffer para uso de read() y write()
  if (pipe(fd) == -1) {
    perror("pipe") ;
    exit(-1) ;
  }
  if ((pid = fork()) == -1) {
    perror("fork") ;
    exit(-1) ;
  }
  else if (pid == 0) { // Proceso hijo 
    while (read(fd[0], buffer, MAX) >0)
      printf("Proceso hijo: %s\n", buffer) ;
    close(fd[0]) ;
    close(fd[1]) ;
    exit(0) ;
  }
  else {  // Proceso padre
    write(fd[1], frase, strlen(frase)+1) ;
    close(fd[0]) ;
    close(fd[1]) ;
    exit(0) ;
  }
}
