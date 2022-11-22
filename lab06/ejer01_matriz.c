/*Ejercicio Matriz */ 
# include <stdio.h>
# include <stdlib.h> 
# include <string.h>
# include <unistd.h> 
# include <pthread.h>
struct parametros { 
  int id;  
  float escalar;
  float matriz [3][3];
};

void init (float m [3][3]) {
  int i;  
  int j;  
  for ( i = 0 ; i < 3 ; i++ ) { 
    for ( j = 0 ; j < 3 ; j++ ) { 
      m[i][j] = random () * 100;   
    }
  }
}

void show (float m [3][3]) {
  int i;   
  int j;  
  for ( i = 0 ; i < 3 ; i++ ) { 
    for ( j = 0 ; j < 3 ; j++ ) { 
      printf("%.2f", m[i][j]);
      printf("\t");
    }
    printf("\n");
  }
}

void * matrizporescalar1( void *arg) {  
  struct parametros *p;
  int i = 0;
  int j;
  p = (struct parametros *) arg ;
  printf (" Hilo %d multiplicando fila %d\n", p -> id , i);
  for ( j = 0 ; j < 3 ; j++ ) {
    p -> matriz [i][j] = p -> matriz [i][j] * p -> escalar ; 
    sleep (5); 
  }
}

void * matrizporescalar2( void *arg) {  
  struct parametros *p;
  int i = 1;
  int j;
  p = (struct parametros *) arg ;
  printf (" Hilo %d multiplicando fila %d\n", p -> id , i);
  for ( j = 0 ; j < 3 ; j++ ) {
    p -> matriz [i][j] = p -> matriz [i][j] * p -> escalar ; 
    sleep (5); 
  }
}

void * matrizporescalar3( void *arg) {  
  struct parametros *p;
  int i = 2;
  int j;
  p = (struct parametros *) arg ;
  printf (" Hilo %d multiplicando fila %d\n", p -> id , i);
  for ( j = 0 ; j < 3 ; j++ ) {
    p -> matriz [i][j] = p -> matriz [i][j] * p -> escalar ; 
    sleep (5); 
  }
}

int main(int argc , char *argv []) {
  pthread_t h1;
  pthread_t h2;
  pthread_t h3;
  struct parametros p1;
  p1.id = 1;
  p1.escalar = 5.0;  
  init (p1.matriz );
  show (p1.matriz );
  pthread_create (&h1 , NULL , matrizporescalar1 , ( void *)&p1);
  pthread_create (&h2 , NULL , matrizporescalar2 , ( void *)&p1);
  pthread_create (&h3 , NULL , matrizporescalar3 , ( void *)&p1);
  pthread_join(h1 , NULL);
  pthread_join(h2 , NULL);
  pthread_join(h3 , NULL);
  show (p1.matriz );
  printf ("Fin \n"); 
}
