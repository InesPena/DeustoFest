#ifndef CONCIERTO_CONCIERTO_H_
#define CONCIERTO_CONCIERTO_H_

#include "../sqlite3/sqlite3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * cod - Código del concierto
 * artista - Nombre del artista
 * escenario - codigo del escenario
 * dia - codigo del día
 */

typedef struct {
	int cod;
	char *artista;
	int escenario;
	int dia;

} Concierto ;


int pedirCodigoConcierto();

void pedirDatosConcierto(sqlite3 *db, Concierto *c);

void insertarConcierto(sqlite3 *db, Concierto *c);

void eliminarConcierto(sqlite3 *db, int cod);

void imprimirCartelera(sqlite3 *db);

#endif /* CONCIERTO_CONCIERTO_H_ */
