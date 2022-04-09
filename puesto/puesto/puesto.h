#ifndef PUESTO_PUESTO_H_
#define PUESTO_PUESTO_H_

#include "../sqlite3/sqlite3.h"

#define MAX_PUESTOS 20

typedef struct
{
	int cod;
	char *marca;
	int coste;

} Puesto;

typedef struct
{
	int numPuestos;
	Puesto *puestos;

} ListaPuestos;

int pedirCodigoPuesto();
void pedirDatosPuesto(sqlite3 *db, Puesto *p);
void insertarPuesto(sqlite3 *db, Puesto *p);
void eliminarPuesto(sqlite3 *db, int cod);

#endif /* PUESTO_PUESTO_H_ */
