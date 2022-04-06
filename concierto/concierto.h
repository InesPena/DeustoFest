#ifndef CONCIERTO_CONCIERTO_H_
#define CONCIERTO_CONCIERTO_H_

#include "../sqlite3/sqlite3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int cod;
	char *artista;
	int escenario;
	int dia;
	int coste;

} Concierto ;


int pedirCodigoConcierto();

void pedirDatosConcierto(sqlite3 *db, Concierto *c);

void insertarConcierto(sqlite3 *db, Concierto *c);

void eliminarConcierto(sqlite3 *db, int cod);

typedef struct {
	int numConciertos;
	Concierto *conciertos;

}Cartelera;

void obtenerCartelera(sqlite3 *db, Cartelera *cart);

void imprimirCartelera(sqlite3 *bd,Cartelera *cart, int op);

#endif /* CONCIERTO_CONCIERTO_H_ */
