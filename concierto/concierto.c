#include "concierto.h"
#include "../artista/artista.h"

#include <stdio.h>

#define MAX_LINE 20

/*
 *Pide los datos relativos a un concierto por consola
 */

void pedirDatosConcierto(Concierto *c, Artista *a)
{
	char str[MAX_LINE];

	pedirDatosArtista(a);
	c->artista = *a;

	printf("Fecha del concierto: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", c->fecha);

	printf("Escenario: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%i", &c->escenario);
}

