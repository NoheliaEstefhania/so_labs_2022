#include <stdio.h> 
#include <pthread.h> 
#include <unistd.h>
int x = 0;
void * add(void* arg) {  
  int i = 0; 
  while (i < 10) {   
    x+=1;
    printf("Hilo 1: %d\n", x); 
    i++; 
    sleep(1); 
  }
  return 0;
}
void * sub(void* arg) {   
  int i = 0; 
  while (i < 10) {   
    x-=1;
    printf("Hilo 2: %d\n", x); 
    i++;  
    sleep(1); 
  }
  return 0;
} 
int main(int argc, char *argv[]){
  pthread_t hilo1;  
  pthread_t hilo2;
  pthread_create(&hilo1, NULL, add, NULL);   
  pthread_create(&hilo2, NULL, sub, NULL);   
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);
  printf("Fin\n");
} 
