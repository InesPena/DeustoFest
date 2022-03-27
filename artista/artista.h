/*
 * artista.h
 *
 *  Created on: 25 mar 2022
 *      Author: anema
 */

#ifndef ARTISTA_H_
#define ARTISTA_H_

typedef struct{
	char dni[10];
	char nombre[10];
	char genero[10];
} Artista;

void ImprimirArtista(Artista a);


#endif /* ARTISTA_H_ */
