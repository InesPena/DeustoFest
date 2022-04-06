#include "entrada.h"
#include "../cliente/cliente.h"

#define PRECIO_CAMP 35.00
#define PRECIO_BUS 47.00

/*
 * Imprime los datos de una entrada por pantalla
 */

void imprimirEntrada(Entrada e)
{



}

/*
 * Calcula el precio de la entrada en función de el tipo de entrada,
 * si se ha elegido bus y si se ha elegido camping
 */

float calularPrecio(Entrada *e, float precioEnt)
{
	int precioTotal = 0;

	precioTotal += precioEnt;
	if (e->camping == 1)  precioTotal += PRECIO_CAMP;
	if (e->bus == 1) precioTotal += PRECIO_BUS;

	return precioTotal;
}

/*
 * Proceso para la compra de entradas
 */

void compraEntradas(Entrada *e, Cliente *c)
{
	int op;
	float precioEnt;

	e->camping = 0;
	e->bus = 0;

	printf("\n\n\tENTRADAS\n");
	printf("--------------------------------\n\n");
	printf("1. Entrada Día 22............75€\n");
	printf("2. Entrada Día 23............80€\n");
	printf("3. Abono completo...........142€\n");

	op = elegirOpcion();

	if (op == 1) precioEnt = 75;
	if (op == 2) precioEnt = 80;
	if (op == 3) precioEnt = 90;

	char op2;
	char op3;

	printf("¿Desa reservar una plaza de camping? (s/n) ");
	fflush(stdout);
	scanf("%c",&op2);
	if (op2 == 's') e->camping = 1;

	printf("¿Desa reservar una plaza de autobus? (s/n) ");
	fflush(stdout);
	scanf("%c",&op3);
	getchar();

	if (op3 == 's') e->bus = 1;

	e->precio = calularPrecio(&e, precioEnt);

	printf("\nIntroduzca sus datos personales...\n\n");
	pedirDatosCliente(&c);
}

/*
 * Inserta una fila en la tabla entrada
 */

void insertEntrada(sqlite3 *db, Entrada *e)
{
	//FALTA POR HACER
}
