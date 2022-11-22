/*Ejercicio Array*/ 
# include <stdio.h>
# include <stdlib.h> 
# include <string.h>
# include <unistd.h> 
# include <pthread.h>
# include <time.h> 
# include <sys/time.h>
# include <sys/types.h>
struct parametros { 
  int id;  
  float array[5100];
};

struct timeval t0 , t1; 
double media = 0.0; 

void init (float a[5100]) {
  int i;  
  for ( i = 0 ; i < 5100 ; i++ ) { 
    a[i] = random () * 100;   
  }
}

void show (float a[5100]) {
  int i;   
  for ( i = 0 ; i < 5100 ; i++ ) { 
    printf("%.2f", a[i]);
  }
}

void * sum_array_n( void *arg) {  
  struct parametros *p;
  int i;
  float sum;
  p = (struct parametros *) arg ;
  printf (" Hilo %d sumando elementos\n", p -> id);
  for ( i = 0 ; i < 5100 ; i++ ) {
    sum = sum + p -> array[i]; 
    //sleep (5); 
  }
  printf (" suma de elementos %.2f\n", sum);
}

void * hilo(void *arg ) {  
  gettimeofday(&t1 , NULL); 
  unsigned int ut1 = t1. tv_sec *1000000+ t1. tv_usec; 
  unsigned int ut0 = t0. tv_sec *1000000+ t0. tv_usec; 
  media += (ut1 -ut0 ); 
}

int main(int argc, char *argv []) {
  int i = 0; 
  pthread_t h;
  pthread_t h1;
  struct parametros p1;
  p1.id = 1;
  init (p1.array );
  //show (p1.array );
  gettimeofday (&t0 , NULL);
  pthread_create (&h1 , NULL , sum_array_n , ( void *)&p1);
  pthread_create (&h , NULL , hilo, NULL);
  pthread_join(h1 , NULL);
  pthread_join(h , NULL);
  /* Tiempo en microsegundos */
  printf (" %f\n", media ); 
  printf ("Fin \n"); 
}
