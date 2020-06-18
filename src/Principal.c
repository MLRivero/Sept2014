/*
 * Principal.c
 *
 *  Created on: 4/4/2017
 *      Author: jose
 */

#include <stdio.h>
#include <stdlib.h>
#include "Sistema.h"
#include <string.h>

int main() {
	LSistema l;
	char idh[3];

	Crear(&l);
	Mostrar(l);
	printf("\n");
	InsertarProceso(&l, 4);
	Mostrar(l);
	printf("\n");
	InsertarProceso(&l, 6);
	Mostrar(l);
	printf("\n");


	strcpy(idh, "h1");
	InsertarHebra(&l, 6, idh, 7);
	Mostrar(l);
	printf("\n");

	strcpy(idh, "h3");
	InsertarHebra(&l, 6, idh, 1);
	Mostrar(l);
	printf("\n");

	InsertarProceso(&l, 1);
	Mostrar(l);
	printf("\n");

	InsertarProceso(&l, 2);
	Mostrar(l);
	printf("\n");

	strcpy(idh, "h2");
	InsertarHebra(&l, 6, idh, 4);
	Mostrar(l);

	printf("\n");

	strcpy(idh, "h8");
	InsertarHebra(&l, 2, idh, 3);
	Mostrar(l);
	printf("\n");
	strcpy(idh, "h5");
	InsertarHebra(&l, 2, idh, 2);
	Mostrar(l);
	printf("\n");

	strcpy(idh, "h7");
	InsertarHebra(&l, 2, idh, 10);
	Mostrar(l);
	printf("\n");

	InsertarProceso(&l, 5);
	Mostrar(l);
	printf("\n");

	//Destruir(&l);
	Mostrar(l);
	printf("\n");
	return 0;
}

//Crea una lista vacia
void Crear(LSistema *l) {
	*l = NULL;
}
//Inserta un proceso por orden de llegada.
void InsertarProceso(LSistema *ls, int numproc) {

	if ((*ls) == NULL) {
		*ls=(LSistema) malloc (sizeof(struct Sistema));
		(*ls)->id = numproc;
		(*ls)->sig = NULL;
		(*ls)->hebra = NULL;
	} else {

		while ((*ls)->sig!= NULL) {
			*ls = (*ls)->sig;
		}
		(*ls)->sig=(LSistema) malloc (sizeof(struct Sistema));
		(*ls)->sig->id = numproc;
		(*ls)->sig->sig = NULL;
		(*ls)->sig->hebra = NULL;
	}

}
//Inserta una hebra en el proceso numproc teniendo en cuenta el orden de prioridad (mayor a menor)
void InsertarHebra(LSistema *ls, int numproc, char *idhebra, int priohebra){
	struct Hebra *ant;

	while((*ls)->id!=numproc){
		printf("ERROR\n");
		*ls = (*ls)->sig;
	}
		printf("ERROR\n");
	if((*ls)->hebra == NULL){
		strcpy((*ls)->hebra->idhebra, idhebra);
		(*ls)->hebra->prioridad=priohebra;
		(*ls)->hebra->sig=NULL;

	} else {
		while ((*ls)->hebra->prioridad>priohebra) {
			ant=(*ls)->hebra;
			(*ls)->hebra=(*ls)->hebra->sig;
		}
		if((*ls)->hebra==NULL){
			(*ls)->hebra=malloc(sizeof(struct Hebra));
			strcpy((*ls)->hebra->idhebra, idhebra);
			(*ls)->hebra->prioridad=priohebra;
			(*ls)->hebra->sig=NULL;
		}else{
			strcpy((*ls)->hebra->idhebra, idhebra);
			(*ls)->hebra->prioridad=priohebra;
			(*ls)->hebra->sig=ant->sig;
			ant->sig=(*ls)->hebra;
		}
	}

}
//Muestra el contenido del sistema
void Mostrar(LSistema ls){
	if (ls==NULL) {
		printf("Lista vacía\n");
		fflush(stdout);
	}
	while(ls!=NULL){
		printf("%d \n",ls->id);
		if(ls->hebra!=NULL){
			while(ls->hebra!=NULL){
				printf("%s , %d \n", ls->hebra->idhebra, ls->hebra->prioridad);
				ls->hebra=ls->hebra->sig;
			}
			fflush(stdout);
		}
		ls=ls->sig;
	}
	fflush(stdout);
}
//Elimina del sistema el proceso con número numproc liberando la memoria de éste y de sus hebras.
void EliminarProc(LSistema *ls, int numproc) {

}
//Destruye toda la estructura liberando su memoria
void Destruir(LSistema *ls);
