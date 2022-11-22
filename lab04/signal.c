#include <sys/types.h> 
#include <signal.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void tratasenial (int);
void main(){ 
  pid_t idProceso; 
  idProceso = fork(); 
  if (idProceso==-1) { 
    perror("No se puede lanzar proceso"); 
    exit(-1);
  }  
  if (idProceso == 0) { 
    printf("id=0\n");
    signal (SIGUSR1, tratasenial); 
    while (1){
      printf("se pausará\n");
      pause();
      printf("terminó la pausa\n");
    } 
  }   
  if (idProceso > 0) {
    printf("id>0\n");
    while (1) { 
      printf("se dormirá\n");
      sleep(1);  
      printf("terminó sleep()\n");
      kill (idProceso, SIGUSR1); 
    } 
  }
} 
void tratasenial (int nsenial) { 
  printf ("Recibida la señal del Padre\n");
}
