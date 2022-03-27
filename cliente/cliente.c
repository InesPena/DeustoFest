/*
 * cliente.c
 *
 *  Created on: 25 mar 2022
 *      Author: IRIA
 */

#include "cliente.h"
#include <stdio.h>

void imprimirCliente(Cliente c){

	printf("Nombre: %s, Dni: %s, Mail: %s, Edad: %d", c.nom, c.dni, c.mail, c.edad);

}
