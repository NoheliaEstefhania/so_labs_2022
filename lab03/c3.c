#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main(void){
  pid_t pid;
  /* fork a child process */    
  pid = fork();
  if (pid < 0){ /* error occurred */ 
    fprintf(stderr, "Fork Failed");
    return 1;   
  }    
  else if (pid == 0) { /* child process */  
    printf("Soy el hijo %d\n", getpid());
  }    
  else { /* parent process */    
    printf("Soy el padre %d\n", getppid());
    execlp("ls","ls","-la",NULL);
  }   
  return 0; 
} 
