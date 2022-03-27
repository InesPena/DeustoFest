/*
 * cliente.h
 *
 *  Created on: 25 mar 2022
 *      Author: IRIA
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_


typedef struct{
	char *nom;
	char dni[10];
	char *mail;
	int edad;
} Cliente;

void imprimirCliente(Cliente c);

#endif /* CLIENTE_H_ */
