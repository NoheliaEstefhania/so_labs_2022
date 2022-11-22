//sigusr1.c
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
sig_atomic_t sigusr1_contador = 0;
void manejador(int nro_senal) {
  ++sigusr1_contador;
  printf("SIGUSR1 se dio %d veces\n", sigusr1_contador);
  //fflush(0);
}
int main() {
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));//memoria
  sa.sa_handler = &manejador;
  sigaction(SIGUSR1, &sa, NULL);
  //las señales son asíncronas, este proceso estará 
  //preparado de acuerdo a lo que tiene en su manejador, 
  //no implica que este proceso se detenga
  while(1);//el proceso sigue haciendo lo que nosotros queremos que haga
  return 0;
}
