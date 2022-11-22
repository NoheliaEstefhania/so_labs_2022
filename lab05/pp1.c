//Nohelia
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#define CLAVE_MSG 2000
#define OK 0
#define ERROR -1
#define INFO 150
#define TIPO2 1 
#define TIPO 7
typedef struct {
	long tipo;
	int info;
} MENSAJE;

typedef struct {
	long tipo;
	int numero;
	//char *nombre;
	float sueldo;
} MENSAJE2;

int main() {
	int qid, qid2, opcion;
	MENSAJE msg;
	MENSAJE2 msg2;
	int lector = 0;
	qid = msgget(CLAVE_MSG, IPC_CREAT | IPC_EXCL | SHM_R | SHM_W);
	if (qid == ERROR) {
		if (errno == EEXIST) {
			printf("Ya existe una cola de mensajes, accediendo...\n");
			qid = msgget(CLAVE_MSG, SHM_R | SHM_W);
			if (qid == ERROR) {
				perror("msgget:");
				exit(errno);
			}
		}
	}
	qid2 = msgget(CLAVE_MSG, IPC_CREAT | IPC_EXCL | SHM_R | SHM_W);
	if (qid2 == ERROR) {
		if (errno == EEXIST) {
			printf("Ya existe una cola de mensajes, accediendo...\n");
			qid2 = msgget(CLAVE_MSG, SHM_R | SHM_W);
			if (qid2 == ERROR) {
				perror("msgget:");
				exit(errno);
			}
		}
        }
	printf("Cola de mensajes creada...\n");
	//proceso que envía el mensaje
	msg.tipo = TIPO; // pid del destinatario
	msg.info = INFO; // informacion a transmitir
	msg2.tipo = TIPO2; // pid del destinatario
	msg2.numero = 555;
	//msg2.nombre;
	msg2.sueldo = 5555;

	printf("Enviando mensaje 1...\n");
	if (msgsnd(qid, &msg, sizeof(MENSAJE) - sizeof(long), 0) == ERROR) {
		perror("msgsnd:");
		exit(errno);
	}
	printf("Mensaje 1 enviado.\n");
	printf("Enviando mensaje 2...\n");
	if (msgsnd(qid2, &msg2, sizeof(MENSAJE2) - sizeof(long), 0) == ERROR) {
		perror("msgsnd:");
		exit(errno);
	}
	printf("Mensaje 2 enviado.\n");
	// Procesos de comunicacion finalizado
	exit(OK);
}
