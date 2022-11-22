#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define TAMANO_BUFFER 1000
pthread_mutex_t mutex;
void *funcionThread(void *parametro);
int buffer[TAMANO_BUFFER];
int main(){
	pthread_t idHilo;
	int error;
	pthread_mutex_init(&mutex, NULL);
	int contador=0;
	int i;
	error=pthread_create(&idHilo,NULL,funcionThread,NULL);
	if (error!=0){
		perror("No puedo crear thread..");
		exit(-1);
	}
	while(1){
		pthread_mutex_lock(&mutex);
		for(i=0;i<TAMANO_BUFFER;i++){
			buffer[i]=contador;
		}
		pthread_mutex_unlock(&mutex);
		contador++;
	}
	return 0;
}
void *funcionThread(void *parametro) {
	int i;
	int elementoDist=0;
	while(1){
		pthread_mutex_lock(&mutex);
		for(i=0;i<TAMANO_BUFFER;i++){
			if (buffer[0]!=buffer[i]){
				elementoDist=1;
				break;
			}
		}
		pthread_mutex_unlock(&mutex);
		if (elementoDist)
			printf("Hijo: Error. Elementos distintos en el buffer\n");
		else
			printf("Hijo: Correcto\n");
	}
}
