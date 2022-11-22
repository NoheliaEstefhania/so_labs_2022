#include <sys/types.h>
#include <stdio.h> 
#include <unistd.h>
int value = 5;
int main(){
  pid_t pid;
  pid = fork();  
  if (pid == 0){ /* child process */ 
    printf("Soy el hijo %d\n", getpid());
    value += 15;
    printf("value = %d\n", value);
    return 0;   
  }else if (pid > 0){ /* parent process */
    printf("Soy el padre %d\n", getppid());
    printf("value = %d\n", value);
    wait(NULL);     
    printf("PARENT: value = %d\n",value); /*LINE A*/     
    return 0;  
  }
}
