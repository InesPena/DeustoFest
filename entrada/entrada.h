#ifndef ENTRADA_ENTRADA_H_
#define ENTRADA_ENTRADA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../sqlite3/sqlite3.h"

#define MAX_ENTRADAS 1000

typedef struct {
	int cod;
	char dni[9];
	int camping;
	int bus;
	float precio;

} Entrada;

typedef struct {
	int numEntradas;
	Entrada entradas[MAX_ENTRADAS];

} Aforo;

void imprimirEntrada(Entrada e);

void comprarEntradas();

void insertEntrada(sqlite3 *db, Entrada *e);

float calularPrecio(Entrada *e, float precioEnt);

#endif /* ENTRADA_ENTRADA_H_ */
