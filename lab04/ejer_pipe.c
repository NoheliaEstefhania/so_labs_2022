#include <stdio.h>
#include <unistd.h> 
#include <errno.h>
#include <stdlib.h>
#include <string.h>  
#define LEER 0 
#define ESCRIBIR 1  
char *frase = "Envia esto a traves de un tubo o pipe"; 
extern int errno;
int main(){  
  int fd[2]; //descriptores de pipes 
  int bytesLeidos;
  char mensaje[100];
  int control;  
  // se crea la tuberia   
  control = pipe(fd);
  if ( control != 0 ) {
    perror("pipe:"); 
    exit(errno);
  }    
  // se crea el proceso hijo  
  control = fork() ; 
  switch(control) {    
    case -1 :   
      perror("fork:"); 
      exit(errno); 
    case 0 :  //proceso hijo
      close(fd[LEER]); 
      printf("escrbiremos\n");
      write(fd[ESCRIBIR], frase, strlen(frase) + 1); //escribe el mensaje
      printf("ya escribimos\n");
      close(fd[ESCRIBIR]);

      exit(0);
    default :  //proceso padre
      close(fd[ESCRIBIR]);  
      printf("leeremos\n");
      bytesLeidos = read(fd[LEER], mensaje, 100);//lee el mensaje 
      printf("Leidos %d bytes : %s\n", bytesLeidos, mensaje);
      printf("ya leimos\n");
      close(fd[LEER]);
  }  
  exit(0); 
}
