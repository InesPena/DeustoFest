#ifndef ENTRADA_ENTRADA_H_
#define ENTRADA_ENTRADA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../sqlite3/sqlite3.h"

#define MAX_ENTRADAS 1000

typedef enum {
	FALSE = 0,
	TRUE = 1,

}BOOLEAN;

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

Aforo selectEntradas(sqlite3 *db);

float calcularAsistencia(Aforo a);

float calcularIngersos(Aforo a);

#endif /* ENTRADA_ENTRADA_H_ */
