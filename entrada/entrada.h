/*
 * entrada.h
 *
 *  Created on: 27 mar 2022
 *      Author: iness
 */

#ifndef ENTRADA_H_
#define ENTRADA_H_

typedef struct {

	typedef enum {
		TIPO_A = 40,	/*Día 21*/
		TIPO_B = 38, 	/*Día 22*/
		TIPO_O = 72, 	/*Día 21 y 22*/

	} TIPO_ENTRADA;

	typedef struct {
		int cod;
		char dni[9];
		TIPO_ENTRADA tipo;
		int camp;
		int bus;

	} Entrada;

};



#endif /* ENTRADA_H_ */
