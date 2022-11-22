/*Ejercicio Matriz */ 
# include <stdio.h>
# include <stdlib.h> 
# include <string.h>
# include <unistd.h> 
# include <pthread.h>
# include <time.h> 
# include <sys/time.h>
# include <sys/types.h>

typedef struct parametros { 
    int id;  
    int n, n1, n2, n3;
    float array[5100];
}parametros;

float sum = 0;
struct timeval t0 , t1; 
double media = 0.0; 

void init (float a[5100]) {
    for (int i = 0 ; i < 5100 ; i++ ) { 
        a[i] = random () % 10;   
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
    p = (struct parametros *) arg ;
    printf("hilo %d\n", p->id);
    for (int i = 0 ; i < p -> n ; i++ ) {
        sum+=p->array[i];
        //printf("elem[%d]:%0.f -> suma:%.f\n", i, p->array[i], sum);
        //sleep (5); 
    }
    printf (" Hilo %d, suma: %f\n", p -> id , sum);
}
void * sum_array_n1( void *arg) {  
    struct parametros *p;
    p = (struct parametros *) arg ;
    printf("hilo %d\n", p->id);
    for (int i = p->n ; i < p -> n1 ; i++ ) {
        sum+=p->array[i];
        //printf("elem[%d]:%0.f -> suma:%.f\n", i, p->array[i], sum);
        //sleep (5); 
    }
    printf (" Hilo %d, suma: %f\n", p -> id , sum);
}
void * sum_array_n2( void *arg) {  
    struct parametros *p;
    p = (struct parametros *) arg ;
    printf("hilo %d\n", p->id);
    for (int i = p->n1 ; i < p -> n2 ; i++ ) {
        sum+=p->array[i];
        //printf("elem[%d]:%0.f -> suma:%.f\n", i, p->array[i], sum);
        //sleep (5); 
    }
    printf (" Hilo %d, suma: %f\n", p -> id , sum);
}
void * sum_array_n3( void *arg) {  
    struct parametros *p;
    p = (struct parametros *) arg ;
    printf("hilo %d\n", p->id);
    for (int i = p->n2 ; i < p -> n3 ; i++ ) {
        sum+=p->array[i];
        //printf("elem[%d]:%0.f -> suma:%.f\n", i, p->array[i], sum);
        //sleep (5); 
    }
    printf (" Hilo %d, suma: %f\n", p -> id , sum);
}

void * hilo(void *arg ) {  
    gettimeofday(&t1 , NULL); 
    unsigned int ut1 = t1. tv_sec *1000000+ t1. tv_usec; 
    unsigned int ut0 = t0. tv_sec *1000000+ t0. tv_usec; 
    media += (ut1 -ut0 ); 
}

void initRanges(parametros *p){
    p->n = 5100/4;
    p->n1 = (5100/4)*2;
    p->n2 = (5100/4)*3;
    p->n3 = 5100;
}

int main(int argc , char *argv []) {
    srand(time(NULL));
    int i = 0; 
    pthread_t h;
    pthread_t h1;
    pthread_t h2;
    pthread_t h3;
    pthread_t h4;
    parametros p1;
    p1.id = 1;

    initRanges(&p1);
    init (p1.array);

    //show (p1.array );
    gettimeofday (&t0 , NULL);
    pthread_create (&h1 , NULL , sum_array_n , ( void *)&p1);
    pthread_join(h1 , NULL);

    p1.id++;
    pthread_create (&h2 , NULL , sum_array_n1, ( void *)&p1);
    pthread_join(h2 , NULL);

    p1.id++;
    pthread_create (&h3 , NULL , sum_array_n2, ( void *)&p1);
    pthread_join(h3 , NULL);

    p1.id++;
    pthread_create (&h4 , NULL , sum_array_n3, ( void *)&p1);
    pthread_join(h4 , NULL);

    printf ("(total-hilos)suma: %f\n", sum);

    pthread_create (&h , NULL , hilo, NULL);
    pthread_join(h , NULL);
    /* Tiempo en microsegundos */
    printf (" %f\n", media ); 
    printf ("Fin \n"); 


    printf("\nSuma seguida\n");
    float sum2 = 0;
    for(int i=0;i<5100;i++){
        sum2+=p1.array[i];
    }
    printf ("(total-seguida)suma: %f\n", sum2);
}
