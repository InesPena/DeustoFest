#ifndef CLIENTE_CLIENTE_H_
#define CLIENTE_CLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

	char dni[10];
	char *nom;
	char *mail;
	int edad;

} Cliente;

void imprimirCliente(Cliente c);

#endif /* CLIENTE_CLIENTE_H_ */
