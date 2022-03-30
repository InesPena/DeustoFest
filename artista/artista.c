/*
 * artista.c
 *
 *  Created on: 25 mar 2022
 *      Author: anema
 */

#include <stdio.h>
#include "artista.h"

void ImprimirArtista(Artista a) {

	printf("Dni: %s\n, Nombre: %s\n, Tipo: %s\n", a.dni, a.nombre, a.genero);
}

