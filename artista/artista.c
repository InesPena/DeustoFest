/*
 * artista.c
 *
 *  Created on: 25 mar 2022
 *      Author: anema
 */

#include <stdio.h>

#include "artista.h"

#define MAX_LINE 20


void imprimirArtista(Artista a)
{

	printf("Dni: %s\n, Nombre: %s\n, Tipo: %s\n", a.cod, a.nombre, a.genero);
}

