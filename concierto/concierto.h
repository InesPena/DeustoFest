#ifndef CONCIERTO_CONCIERTO_H_
#define CONCIERTO_CONCIERTO_H_

#include "../artista/artista.h"

typedef struct {
	int cod;
	char fecha[11];
	int escenario;
	Artista artista;

} Concierto ;

typedef struct {
	int numConciertos;
	Concierto *conciertos;

} Cartelera;

void pedirDatosConcierto(Concierto *c, Artista *a);

#endif /* CONCIERTO_CONCIERTO_H_ */
