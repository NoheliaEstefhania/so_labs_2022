#include <sys/types.h> 
#include <signal.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void tratasenial (int);
void main(){ 
  pid_t idProceso, idProceso2, idProceso3; 
  idProceso = fork(); 
  if (idProceso==-1) { 
    perror("No se puede lanzar proceso\n"); 
    exit(-1);
  }  
  if (idProceso == 0) { //child
    printf("--> soy el hijo 1, mi PID es %d, y el de mi padre es %d\n", getpid(), getppid());
    while (1){
      printf("se dormirá\n");
      sleep(20);  
      printf("terminó sleep()\n");
      kill (idProceso, SIGUSR1); 
    } 
    idProceso2 = fork(); 
    wait(NULL); 
    if(idProceso2 == 0){
      printf("--> soy el nieto o hijo 3 : ejecutaré un script\n");
    }
  }   
  if (idProceso > 0) { //parent
    printf("--> soy el padre\n");
    idProceso3 = fork();
    wait(NULL);
    if(idProceso3 == 0){
      printf("--> soy el 2do hijo\n");
      signal (SIGUSR1, tratasenial); 
    }
    while (1) { 
      printf("se pausará\n");
      pause();
      printf("terminó la pausa\n");
    } 
  }
} 
void tratasenial (int nsenial) { 
  printf ("Recibida la señal del hijo 1\n");
  printf("mi PID es %d\n", getpid());
  sleep(5);
}
