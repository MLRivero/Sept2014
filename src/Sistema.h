/*
 * Sistema.h
 *
 *  Created on: 4/4/2017
 *      Author: jose
 */

#ifndef __SISTEMA__
#define __SISTEMA__

// Definici�n del tipo LSistema
typedef struct Sistema *LSistema;
struct Sistema {
	int id;
	LSistema sig;
	struct Hebra *hebra;

};

struct Hebra {
	char idhebra[2];
	int prioridad;
	struct Hebra *sig;
};


//Crea una lista vacia
void Crear(LSistema *l);
//Inserta un proceso por orden de llegada.
void InsertarProceso ( LSistema *ls, int numproc);
//Inserta una hebra en el proceso numproc teniendo en cuenta el orden de prioridad (mayor a menor)
void InsertarHebra (LSistema *ls, int numproc, char *idhebra, int priohebra);
//Muestra el contenido del sistema
void Mostrar (LSistema ls);
//Elimina del sistema el proceso con n�mero numproc liberando la memoria de �ste y de sus hebras.
void EliminarProc (LSistema *ls, int numproc);
//Destruye toda la estructura liberando su memoria
void Destruir (LSistema *ls);


#endif
