/*
 * entrada.h
 *
 *  Created on: 30 mar 2022
 *      Author: iness
 */

#ifndef ENTRADA_ENTRADA_H_
#define ENTRADA_ENTRADA_H_

typedef enum {
	DIA_1 = 40,
	DIA_2 = 38,
	COMPLETA = 72,

} TIPO_ENTRADA;

typedef struct {
	int cod;
	char dni[9];
	TIPO_ENTRADA tipo;
	int camp;
	int bus;

} Entrada;

#endif /* ENTRADA_ENTRADA_H_ */
