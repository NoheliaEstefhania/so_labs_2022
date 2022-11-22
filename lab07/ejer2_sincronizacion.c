#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
int length = 20;
void *funcion01(void *arg){
  int i;
  for (i = 0; i < length; i++){
  //  printf("%d",length);
    printf("+");
    fflush(stdout);
    //sleep(1);
  }
  length--;
  printf("\n");
  return NULL;
}
void *funcion02(void *arg){
  int i;
  for (i = 0; i < length; i++){
    printf("o");
    fflush(stdout);
 //   sleep(1);
  }
  length -= 2;
  printf("\n");
  return NULL;
}
int main(){
  pthread_t mihilo01, mihilo02;
  int length = 20;
  for (int i = 0; i < 20; i++){
    if (pthread_create(&mihilo01, NULL, funcion01, NULL)){
      printf("Error creando el hilo.");
      abort();
    }
    pthread_join(mihilo01, NULL);
    if (pthread_create(&mihilo02, NULL, funcion02, NULL)){
      printf("Error creando el hilo.");
      abort();
    }
    pthread_join(mihilo02, NULL);

    length = length - 3;
    for (int j = 0; j < length; j++){
      printf("x");
      fflush(stdout);
//      sleep(3);
    }
    printf("\n");
  }
  exit(0);
}
