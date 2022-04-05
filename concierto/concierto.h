#ifndef CONCIERTO_CONCIERTO_H_
#define CONCIERTO_CONCIERTO_H_

#include "../sqlite3/sqlite3.h"

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

void pedirDatosConcierto(Concierto *c);

void selectEscenarios(sqlite3 *db);

void insertarConcierto(sqlite3 *db, Concierto c);

#endif /* CONCIERTO_CONCIERTO_H_ */
