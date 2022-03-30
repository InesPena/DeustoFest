/*
 * cliente.c
 *
 *  Created on: 25 mar 2022
 *      Author: IRIA
 */

#include "cliente.h"

#include <stdio.h>

/**
 * Pide los datos del cliente por pantalla y los almacena
 */

void pedirDatosCliente(Cliente *c)
{
		char str[MAX_LINE];

		char *nom;
		char dni[10];
		char *mail;

		printf("Nombre: ");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%s", &nom);
		cliente->nom = nom;

		printf("DNI: ");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%s", &dni);
		cliente->dni = dni;

		printf("E-mail: ");
		fflush(stdout);
		fgets(str, MAX_LINE, stdin);
		sscanf(str, "%s", &mail);
		cliente->mail = mail;
}

/**
 * Imprime los datos de un cliente por pantalla
 */

void imprimirCliente(Cliente c)
{
	printf("Nombre: %s, Dni: %s, Mail: %s, Edad: %d", c.nom, c.dni, c.mail, c.edad);
}
