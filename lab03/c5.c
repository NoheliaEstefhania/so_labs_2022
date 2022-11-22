#include <stdio.h> 
int main(void){
  int pid;
  /* Creamos un nuevo proceso. */ 
  pid = fork();  
  if (pid == 0) { 
    printf("Buenos ");
  }  
  else if (pid > 0) {
    printf("Hola \n"); 
    /* Creamos un nuevo proceso. */ 
    pid = fork();
    wait(NULL);    
    if (pid == 0) {
      printf("dias ");   
    }
    else if (pid > 0) { 
      /* Creamos un nuevo proceso. */ 
      pid = fork();
      wait(NULL);
      if (pid == 0) {
        printf("tenga \n");   
      }
    }
    else 
      printf("Ha habido algun error al llamar por 2a vez al fork\n");
  }
  else
    printf("Ha habido algun error al llamar a fork\n");
}
