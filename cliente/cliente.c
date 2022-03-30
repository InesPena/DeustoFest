#include "cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 20

/**
 * Pide los datos a un cliente y lo añade a muna lista de clientes
 */

void anadirCliente(Cliente *c)
{
	char str[MAX_LINE];

	char dni[10];
	char nom;
	char mail;

	char temp[10];
	int size;

	printf("DNI: ");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);
	sscanf(str, "%s", &dni);


	printf("Nombre: ");
	fflush(stdout);
	fgets(temp, MAX_LINE, stdin);
	sscanf(temp, "%s", temp);
	size = strlen(temp);
	c->nom = malloc((size + 1) * sizeof(char));
	strcpy(c->nom, temp);
	free(temp);

	printf("Email: ");
	fflush(stdout);
	fgets(temp, MAX_LINE, stdin);
	sscanf(temp, "%s", temp);
	size = strlen(temp);
	c->mail = malloc((size + 1) * sizeof(char));
	strcpy(c->mail, temp);
	free(temp);
}
