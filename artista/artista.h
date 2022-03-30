/*
 * artista.h
 *
 *  Created on: 25 mar 2022
 *      Author: anema
 */

#ifndef ARTISTA_H_
#define ARTISTA_H_

typedef enum {
	POP,
	REGGAETON,
	RAP,
	URBAN,

} GENERO;

typedef struct{
	int cod;
	char *nombre;
	GENERO genero;

} Artista;

Artista anadirArtista();

void imprimirArtista(Artista a);


#endif /* ARTISTA_H_ */
