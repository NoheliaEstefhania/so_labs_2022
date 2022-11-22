#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int crear(char* programa, char** argumentos) {
  pid_t pid_hijo;
  pid_hijo = fork();
  if(pid_hijo!=0) {
    printf("soy el padre %d %d \n", pid_hijo, getpid());
    sleep(20);
    return pid_hijo;
  }else{  
    printf("Soy el hijo %d y mi padre es %d\n", getpid(), getppid());
    execvp(programa, argumentos);
    fprintf(stderr, "se dio un error");
    abort();
  }  
}   
int main() {
  char* argumentos[] = {"ls", "-lh", "/", NULL};
  crear("ls", argumentos);
  return 0;
} 
